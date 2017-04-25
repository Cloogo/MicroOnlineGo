#include "Nickname.h"
#include "Proto.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

Nickname::Nickname(Json in){
    nickname=in["nickname"].as_string();
}

Json
Nickname::check(){
    std::string stm="select * from users where nickname=\""+nickname+"\"";
    if(SqlStm::isExisted(stm)){
        out["response type"]=int(T::NICKNAME_CHECK_FAILED);
        out["reason"]="nickname has been used";
    }else{
        out["response type"]=int(T::NICKNAME_CHECK_SUCCESS);
        out["reason"]="nickname can be used";
    }
    return out;
}

Json
Nickname::handle(){
    return check();
}
