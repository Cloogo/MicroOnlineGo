#include "PacketParser.h"
#include "Proto.h"
#include "Account.h"
#include "Login.h"
#include "Logout.h"
#include "Regist.h"
#include "RoomManager.h"
#include "LobbyInfo.h"
#include "RoomInfo.h"
#include "PlayerInfo.h"
#include "PlayersInfo.h"
#include "GroupChat.h"
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
    switch(T(in["request_type"].as_number())){
        case T::ACCOUNT_CHECK:
        {
            Account account(in);
            out=account.handle();
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
            decode();
            return;
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
        case T::GROUP_CHAT:
        {
            GroupChat groupChat(in);
            out=groupChat.handle();
        }
        break;
        case T::SITDOWN:
        break;
        case T::LEAVE:
        break;
        case T::READGO:
        break;
        case T::GIVEUP:
        break;
        case T::PLACECHESS:
        break;
        case T::GAMEOVER_WINNER:
        break;
        case T::GAMEOVER_LOSER:
        break;
        case T::SEND_MSG:
        break;
    }
    encode();
}
