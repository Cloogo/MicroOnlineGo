#include "Regist.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;

Regist::Regist(Json in){
    account=in["account"].as_string();
    nickname=in["nickname"].as_string();
    passwd=in["passwd"].as_string();
//    time=in["regist_time"].as_string();
}

Json
Regist::handle(){
    std::string stm="insert into users value(\""+account+"\",\""+nickname+"\",\""+passwd+"\",1,0,\"Offline\")";
    if(SqlStm::silence(stm)){
        out["response type"]=int(T::REGIST_SUCCESS);
    }else{
        out["response type"]=int(T::REGIST_FAILED);
        out["reason"]="inner server error";
    }
    return out;
}
