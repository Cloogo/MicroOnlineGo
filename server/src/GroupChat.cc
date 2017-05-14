#include "Proto.h"
#include "GroupChat.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE
using namespace muduo::net;
using namespace redbud::parser::json;

GroupChat::GroupChat(const Json& in){
    account=in["account"].as_string();
    msg=in["message"].as_string();
}

Json
GroupChat::handle(){
    Json toall;
    toall["response_type"]=static_cast<int>(T::GROUP_CHAT_MSG);
    toall["account"]=account;
    toall["message"]=msg;
    RoomManager::getInstance().broadcast2(conn,0,toall.dumps());
    out["response_type"]=static_cast<int>(T::GROUP_CHAT_SUCCESS);
    return out;
}

void
GroupChat::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
