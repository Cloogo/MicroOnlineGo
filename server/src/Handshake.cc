#include "Handshake.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"
#include <muduo/base/Logging.h>

#define T RESPONSE_TYPE
using namespace redbud::parser::json;
using namespace muduo::net;
using namespace std;

Handshake::Handshake(const Json& in){
    roomid=in["room"].as_number();
    player1Ready=in["player1"].as_bool();
    player2Ready=in["player2"].as_bool();
}

Json
Handshake::handle(){
    string stm0;
    if(player1Ready){
        stm0="update rooms set player1ready=1 where id="+to_string(roomid);
    }else if(player2Ready){
        stm0="update rooms set player2ready=1 where id="+to_string(roomid);
    }
    LOG_INFO<<"Handshake: stm0: "<<stm0;
    if(SqlStm::silence(stm0)){
        string stm1="select * from rooms where id="+to_string(roomid);
        string stm2="select * from rooms where id="+to_string(roomid);
        if(SqlStm::getField(stm1,"player1ready")==true&&SqlStm::getField(stm2,"player2ready")==true){
            string stm3="update rooms set state="+to_string(static_cast<int>(ROOM_STATE::GAMING))+" where id"+to_string(roomid);
            if(SqlStm::silence(stm3)){
                Json toall;
//                toall["response_type"]=static_cast<int>(T::BROADCAST_READYGO);
                toall["room"]=SqlStm::getRoom(roomid);               
                toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_ROOM);

            }
        }
        out["response_type"]=static_cast<int>(T::READYGO_SUCCESS);
        return out;
    }
    out["response_type"]=static_cast<int>(T::READYGO_FAILED);
    out["reason"]="inner server error";
    return out;
}

void
Handshake::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
