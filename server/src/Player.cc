#include "Player.h"
#include "Proto.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE

using namespace std;
using namespace redbud::parser::json;
using namespace muduo::net;

Player::Player(const Json& in_){
    in=in_;
    account =in["account"].as_string();
    nickname=in["nickname"].as_string();
    passwd  =in["password"].as_string();
    level   =in["data"]["level"].as_number();
    rank    =in["data"]["rank"].as_number();
    win     =in["data"]["win"].as_number();
    lose    =in["data"]["lose"].as_number();
    draw    =in["data"]["draw"].as_number();
    year    =in["birthday"]["year"].as_number();
    month   =in["birthday"]["month"].as_number();
    day     =in["birthday"]["day"].as_number();
    state   =in["state"].as_number();
    sex     =in["sex"].as_bool();
    roomid  =in["room"].as_number();
}

Json
Player::handle(){
    update();
    return out;
}

bool
Player::update(){
    bool ok=false;
    std::string stm="update users set "
        "level="+to_string(level)+","
        "rank="+to_string(rank)+","
        "win="+to_string(win)+","
        "lose="+to_string(lose)+","
        "draw="+to_string(draw)+","
        "state="+to_string(state)+","
        "id="+to_string(roomid)+
        " where account=\""+account+"\"";
    if(SqlStm::silence(stm)){
        ok=true;
        notify();
    }else{
#if 0
        out["response_type"]=static_cast<int>(T::FETCH_PLAYER_INFO_FAILED);
        out["reason"]="inner server error";
#endif
    }
    return ok;
}

bool
Player::notify(){
   in.erase("request_type");
   Json toall=in;
   toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_PLAYER);
   toall["user"]=in;
   RoomManager::getInstance().broadcast(0,toall.dumps());
   return true;
}

void
Player::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
