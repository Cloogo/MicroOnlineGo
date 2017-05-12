#include "PacketParser.h"
#include "Proto.h"
#include "Account.h"
#include "Nickname.h"
#include "Login.h"
#include "Logout.h"
#include "Regist.h"
#include "RoomManager.h"
#include "PairManager.h"
#include "LobbyInfo.h"
#include "RoomInfo.h"
#include "PlayerInfo.h"
#include "PlayersInfo.h"
#include "GroupChat.h"
#include "Player.h"
#include "Room.h"
#include "Handshake.h"
#include "ChessInfo.h"
#include "SinglecastMsg.h"
#include "GameResult.h"
#include "BookSeat.h"
#include <redbud/parser/json_parser.h>
#define T REQUEST_TYPE

using namespace redbud::parser::json;
using namespace std;

void
PacketParser::encode(){
    auto str=out.dumps();
    sendBack(conn,str);
}

void
PacketParser::decode(){
    in=Json::parse(msg);
}

void
PacketParser::dispatch(){
    decode();
    switch(T(static_cast<int>(in["request_type"].as_number()))){
        case T::ACCOUNT_CHECK:
        {
            Account account(in);
            out=account.handle();
        }
        break;
        case T::NICKNAME_CHECK:
        {
            Nickname nickname(in);
            out=nickname.handle();
        }
        break;
        case T::LOGIN:
        {
            Login login(in);
            out=login.handle();
            RoomManager::getInstance().add(conn,0);
        }
        break;
        case T::REGIST:
        {
            Regist regist(in);
            out=regist.handle();
        }
        break;
        case T::LOGOUT:
        {
            Logout logout(in);
            out=logout.handle();
            RoomManager::getInstance().remove(conn,0);
        }
        break;
        case T::SEND_MSG:
        {
            SinglecastMsg singlecastMsg(in);
            singlecastMsg.setConn(conn);
            out=singlecastMsg.handle();
        }
        break;
        case T::GROUP_CHAT:
        {
            GroupChat groupChat(in);
            groupChat.setConn(conn);
            out=groupChat.handle();
        }
        break;
        case T::PLACECHESS:
        {
            ChessInfo chessInfo(in);
            chessInfo.setConn(conn);
            out=chessInfo.handle();
        }
        break;
        case T::FETCH_PLAYER_INFO:
        {
            PlayerInfo playerInfo(in);
            out=playerInfo.handle();
        }
        break;
        case T::FETCH_PLAYERS_INFO:
        {
            PlayersInfo playersInfo(in);
            out=playersInfo.handle();
        }
        break;
        case T::FETCH_LOBBY_INFO:
        {
            LobbyInfo lobbyInfo(in);
            out=lobbyInfo.handle();
        }
        break;
        case T::FETCH_ROOM_INFO:
        {
            RoomInfo roomInfo(in);
            out=roomInfo.handle();
        }
        break;
        case T::UPDATE_PLAYER:
        {
#if 0
           Table table(in);
           table.setConn(conn);
           out=table.handle();
#endif
           Player player(in);
           player.setConn(conn);
           out=player.handle();
        }
        break;
        case T::UPDATE_ROOM:
        {
            Room room(in);
            room.setConn(conn);
            out=room.handle();
        }
        break;
        case T::READYGO:
        {
            Handshake handShake(in);
            handShake.setConn(conn);
            out=handShake.handle();
        }
        break;
        case T::UPDATE_GAMERESULT:
        {
            GameResult gameResult(in);
            gameResult.setConn(conn);
            out=gameResult.handle();
        }
        break;
        case T::SITDOWN:
        {
            BookSeat bookSeat(in);
            bookSeat.setConn(conn);
            out=bookSeat.handle();
        }
        break;
        case T::JUDGE:
        {
            in.erase("request_type");
            Json torival=in;
            torival["response_type"]=static_cast<int>(RESPONSE_TYPE::JUDGE);
            PairManager::getInstance().singlecast(conn,static_cast<int>(in["room_id"].as_number()),torival.dumps());
        }
        break;
#if 0
        case T::SITDOWN:
        {
            ORDER order=PairManager::getInstance().add(conn,in["id"].as_number());
            in["order"]=static_cast<int>(order);
            if(static_cast<int>(in["id"].as_number())==0){
                in["id"]=conn->localAddress().toPort();
                NewRoom newRoom(in);
                out=newRoom.handle();
            }else{
                NewRival newRival(in);
                out=newRival.enter();
            }
            PairManager::getInstance().add(conn,in["id"].as_number());
        }
        break;
        case T::LEAVE:
        {
            ORDER order=PairManager::getInstance().pos(conn,in["room"].as_number());
            in["order"]=static_cast<int>(order);
            NewRival newRival(in);
            out=newRival.leave();
            PairManager::getInstance().remove(conn,in["room"].as_number());
        }
        break;
#endif
    }
    encode();
}
