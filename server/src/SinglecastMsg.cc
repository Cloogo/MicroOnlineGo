#include "SinglecastMsg.h"
#include "Proto.h"
#include "PairManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

SinglecastMsg::SinglecastMsg(Json in){
}

Json
SinglecastMsg::handle(){
    in.erase("request_type");
    out=in;
    out["response_type"]=int(T::SEND_MSG_SUCCESS);
    return out;
}
