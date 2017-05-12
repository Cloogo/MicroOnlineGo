#include "Table.h"
#include "Proto.h"
#include "PairManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE

using namespace std;
using namespace redbud::parser::json;
using namespace muduo::net;

Table::Table(const Json& in_){
    in=in_;
 
//    action=ACTION(in["action"].as_number());
}

Json
Table::handle(){
    update();
    return out;
}

void
Table::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}

bool
Table::update(){
    bool ok=false;
   string stm0="update users set state="+to_string(static_cast<int>(STATE::READY))+" where account=\""+account+"\"";
   if(SqlStm::silence(stm0)){
       notify();
       ok=true;
   }
   return ok;
}

bool
Table::leave(){
    bool ok=false;
   string stm0="update users set state="+to_string(static_cast<int>(STATE::IDLE))+" where account=\""+account+"\"";
   if(SqlStm::silence(stm0)){
       notify();
       ok=true;
   }
   return ok;
}

bool
Table::notify(){
   in.erase("request_type");
   Json torival=in;
   torival["response_type"]=static_cast<int>(T::SINGLECAST_UPDATE_PLAYER);
   PairManager::getInstance().singlecast(conn,roomid,torival.dumps());
   Json toall;
   toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_PLAYER);
   toall["user"]=in;
   RoomManager::getInstance().broadcast(0,toall.dumps());
   return true;
}

#if 0
Json
Table::handle(){
    switch(action){
    case ACTION::IN:
        if(enter()){
            out["response_type"]=static_cast<int>(T::SITDOWN_SUCCESS);
//            PairManager::getInstance().add(conn,roomid);
        }else{
            out["response_type"]=static_cast<int>(T::SITDOWN_FAILED);
        }
    break;
    case ACTION::OUT:
        if(leave()){
            out["response_type"]=static_cast<int>(T::LEAVE_SUCCESS);
//            PairManager::getInstance().remove(conn,roomid);
        }else{
            out["response_type"]=static_cast<int>(T::LEAVE_FAILED);
        }   
    break;
    }
    return out;
}

void
Table::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}

bool
Table::enter(){
    bool ok=false;
   string stm0="update users set state="+to_string(static_cast<int>(STATE::READY))+" where account=\""+account+"\"";
   if(SqlStm::silence(stm0)){
       notify();
       ok=true;
   }
   return ok;
}

bool
Table::leave(){
    bool ok=false;
   string stm0="update users set state="+to_string(static_cast<int>(STATE::IDLE))+" where account=\""+account+"\"";
   if(SqlStm::silence(stm0)){
       notify();
       ok=true;
   }
   return ok;
}

bool
Table::notify(){
   in.erase("request_type");
   Json torival=in;
   torival["response_type"]=static_cast<int>(T::SINGLECAST_UPDATE_PLAYER);
   PairManager::getInstance().singlecast(conn,roomid,torival.dumps());
   Json toall;
   toall["response_type"]=static_cast<int>(T::BROADCAST_UPDATE_PLAYER);
   toall["user"]=in;
   RoomManager::getInstance().broadcast(0,toall.dumps());
   return true;
}
#endif


