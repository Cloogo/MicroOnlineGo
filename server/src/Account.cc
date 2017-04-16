#include "Account.h"
#include "Proto.h"
#include "SqlManager.h"
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
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    std::string stm="select * from users where account=\""+account+"\"";
    ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
    if(ResultSet_next(r)){
        out["response type"]=EXISTED;
    }else{
        out["response type"]=NOT_EXISTED;
    }
    return out;
}
