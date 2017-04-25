#include "SinglecastMsg.h"
#include "Proto.h"
#include "PairManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

SinglecastMsg::SinglecastMsg(Json in){
    nickname=in["nickname"].as_string();
    msg=in["msg"].as_string();
}

Json
SinglecastMsg::handle(){
    out["nickname"]=nickname;
    out["msg"]=msg;
    out["response_type"]=int(T::SEND_MSG_SUCCESS);
    return out;
}
