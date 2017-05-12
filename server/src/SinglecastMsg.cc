#include "SinglecastMsg.h"
#include "Proto.h"
#include "PairManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace muduo::net;

SinglecastMsg::SinglecastMsg(const Json& in){
    roomid=in["room_id"].as_number();
    account=in["account"].as_string();
    msg=in["message"].as_string();
}

Json
SinglecastMsg::handle(){
    out["account"]=account;
    out["message"]=msg;
    torival=out;
    torival["response_type"]=static_cast<int>(RESPONSE_TYPE::SINGLECAST_CHAT);
    PairManager::getInstance().singlecast(conn,roomid,torival.dumps());
    out["response_type"]=static_cast<int>(T::SEND_MSG_SUCCESS);
    return out;
}

void 
SinglecastMsg::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
