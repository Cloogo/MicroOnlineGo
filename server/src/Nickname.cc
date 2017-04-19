#include "Nickname.h"
#include "Proto.h"
#include "SqlStm.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define NOT_EXISTED 1
#define EXISTED 0

using namespace redbud::parser::json;

Nickname::Nickname(Json in){
    nickname=in["nickname"].as_string();
}

Json
Nickname::check(){
    std::string stm="select * from users where nickname=\""+nickname+"\"";
    if(SqlStm::isExisted(stm)){
        out["response type"]=EXISTED;
    }else{
        out["response type"]=NOT_EXISTED;
    }
    return out;
}

Json
Nickname::handle(){
    return check();
}
