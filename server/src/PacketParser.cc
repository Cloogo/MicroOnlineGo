#include "PacketParser.h"
#include "Proto.h"
#include <redbud/parser/json_parser.h>
using namespace redbud::parser::json;
using namespace std;

void
PacketParser::encode(){
    auto str=out.dumps();
    msgCb(conn,str);
}

void
PacketParser::decode(){
    in=Json::parse(msg);
}

void
PacketParser::dispatch(){
    decode();
    switch(REQUEST_TYPE(in["request type"])){
        case REQUEST_TYPE::LOGIN:
            Login login(in);
            out=login.handle();
            break;
        case REQUEST_TYPE::REGIST:
            Regist regist(in);
            out=regist.handle();
        break;
        case REQUEST_TYPE::LOGOUT:
        break;
        case REQUEST_TYPE::FETCH_PLAYER_INFO:
        break;
        case REQUEST_TYPE::FETCH_LOBBY_INFO:
        break;
        case REQUEST_TYPE::FETCH_ROOM_INFO:
        break;
        case REQUEST_TYPE::SIT_DOWN:
        break;
        case REQUEST_TYPE::LEAVE:
        break;
        case REQUEST_TYPE::READGO:
        break;
        case REQUEST_TYPE::GIVEUP:
        break;
        case REQUEST_TYPE::PLACECHESS:
        break;
        case REQUEST_TYPE::GAMEOVER_WINNER:
        break;
        case REQUEST_TYPE::GAMEOVER_LOSER:
        break;
        case REQUEST_TYPE::SEND_MSG:
        break;
    }
    encode();
}
