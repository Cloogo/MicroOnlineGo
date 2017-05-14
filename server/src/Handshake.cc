#include "Proto.h"
#include "Handshake.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"
#include "PairManager.h"
#include <muduo/base/Logging.h>

#define T RESPONSE_TYPE
using namespace std;
using namespace muduo::net;
using namespace redbud::parser::json;

Handshake::Handshake(const Json& in){
    roomid=in["room_id"].as_number();
    player1Ready=in["player1"].as_bool();
    player2Ready=in["player2"].as_bool();
}

Json
Handshake::handle(){
    string stm0;
    if(player1Ready){
        stm0="update rooms set player1ready=1 where id="+to_string(roomid);
    }
    if(player2Ready){
        stm0="update rooms set player2ready=1 where id="+to_string(roomid);
    }
    if(SqlStm::silence(stm0)){
//        string stm1="select * from rooms where id="+to_string(roomid);
//        string stm2="select * from rooms where id="+to_string(roomid);
//        if(SqlStm::getField(stm1,"player1ready")==true&&SqlStm::getField(stm2,"player2ready")==true){
//            string stm3="update rooms set state="+to_string(static_cast<int>(ROOM_STATE::GAMING))+" where id"+to_string(roomid);
//            if(SqlStm::silence(stm3)){
//                Json toall;
//                toall["response_type"]=static_cast<int>(T::BROADCAST_READYGO);
//                toall["room"]=SqlStm::getRoom(roomid);               
//                toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_ROOM);
//                out["player1"]=true;
//                out["player2"]=true;
//            }else{
//                out["player1"]=player1Ready;
//                out["player2"]=player2Ready;
//            }
//        }else{
                out["player1"]=player1Ready;
                out["player2"]=player2Ready;
//        }
        out["room_id"]=roomid;
        out["response_type"]=static_cast<int>(T::READYGO_SUCCESS);
        PairManager::getInstance().singlecast(conn,roomid,out.dumps());
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
