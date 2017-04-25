#include "Account.h"
#include "Proto.h"
#include "SqlStm.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define NOT_EXISTED 1
#define EXISTED 0

using namespace redbud::parser::json;

Account::Account(Json in){
    account=in["account"].as_string();
}

Json
Account::check(){
    std::string stm="select * from users where account=\""+account+"\"";
    if(SqlStm::isExisted(stm)){
        out["response_type"]=EXISTED;
    }else{
        out["response_type"]=NOT_EXISTED;
    }
    return out;
}

Json
Account::handle(){
    return check();
}
