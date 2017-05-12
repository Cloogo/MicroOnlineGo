#include "Room.h"
#include "Proto.h"
#include "PairManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE

using namespace std;
using namespace redbud::parser::json;
using namespace muduo::net;

Room::Room(const Json& in_){
    in=in_;
    roomid=in["id"].as_number();
    name=in["name"].as_string();
    player1=in["player1"].as_string();
    player2=in["player2"].as_string();
    state=in["state"].as_number();
    komi=in["config"]["komi"].as_number();
    mainTime=in["config"]["mainTime"].as_number();
    period=in["config"]["period"].as_number();
    periodTimes=in["config"]["periodTimes"].as_number();
    action=PLAYER_ACTION(in["action"].as_number());
}

Json
Room::handle(){
    switch(action){
    case PLAYER_ACTION::PLAYER1IN:
    {
        string stm0="select * from rooms where id="+to_string(roomid);
        if(SqlStm::isExisted(stm0)){
            string stm1="update rooms set player1=\""+player1+"\""+",state="+to_string(state)+" where id="+to_string(roomid);
            if(SqlStm::silence(stm1)){
            }else{
            }
        }else{
            string stm1="insert into rooms values("
                +to_string(roomid)+","
                +"\""+name+"\""+","
                "\""+player1+"\""+","
                "\""+player2+"\""+","
                +to_string(state)+","
                +to_string(komi)+","
                +to_string(mainTime)+","
                +to_string(period)+","
                +to_string(periodTimes)
                +",0,0)";
            if(SqlStm::silence(stm1)){
            }else{
                out["response_type"]=static_cast<int>(T::UPDATE_ROOM_FAILED);
                return out;
            }
        }
        PairManager::getInstance().add(conn,roomid);
    }
    break;
    case PLAYER_ACTION::PLAYER2IN:
    {
        string stm1="update rooms set player2=\""+player2+"\""+",state="+to_string(state)+" where id="+to_string(roomid);
        if(SqlStm::silence(stm1)){
        }else{
        }
        PairManager::getInstance().add(conn,roomid);
    }
    break;
    case PLAYER_ACTION::PLAYER1OUT:
    {
        string stm1="update rooms set player1=\"\",state="+to_string(state)+" where id="+to_string(roomid);
        if(SqlStm::silence(stm1)){
        }else{
        }
        PairManager::getInstance().remove(conn,roomid);
    }
    break;
    case PLAYER_ACTION::PLAYER2OUT:
    {
        string stm1="update rooms set player2=\"\",state="+to_string(state)+" where id="+to_string(roomid);
        if(SqlStm::silence(stm1)){
        }else{
        }
        PairManager::getInstance().remove(conn,roomid);
    }
    break;
    case PLAYER_ACTION::DESTROY:
    {
        destroy();
    }
    break;
    }
    Json toall;
    toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_ROOM);
    in.erase("action");
    toall["room"]=in;
    toall["action"]=static_cast<int>(action);
    RoomManager::getInstance().broadcast(0,toall.dumps());
    out["response_type"]=static_cast<int>(T::UPDATE_ROOM_SUCCESS);
    return out;
}

bool
Room::destroy(){
    bool ok=false;
    string stm0="delete from rooms where id="+to_string(roomid);
    if(SqlStm::silence(stm0)){
        ok=true;
    }
    return ok;
}

void
Room::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
