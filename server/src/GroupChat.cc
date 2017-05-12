#include "GroupChat.h"
#include "RoomManager.h"
#include "Proto.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace muduo::net;

GroupChat::GroupChat(const Json& in){
    account=in["account"].as_string();
    msg=in["message"].as_string();
}

Json
GroupChat::handle(){
    Json msgtoall;
    msgtoall["response_type"]=static_cast<int>(T::GROUP_CHAT_MSG);
    msgtoall["account"]=account;
    
    msgtoall["message"]=msg;
    RoomManager::getInstance().broadcast2(conn,0,msgtoall.dumps());
    out["response_type"]=static_cast<int>(T::GROUP_CHAT_SUCCESS);
    return out;
}

void
GroupChat::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}


