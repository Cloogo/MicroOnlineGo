#include "Account.h"
#include "Proto.h"
#define ACCOUNT_NOT_EXISTED 1
#define ACCOUNT_EXISTED 0

using namespace redbud::parser::json;

Account::Account(Json in){
    account=in["account"].as_string();
}

Json
Account::check(){
    Connection_T sqlConn=Sqlconn::getConn();
    ResultSet_T r=Connection_executeQuery(sqlConn,"select * from users where account=\""+account+"\"");
    while(ResultSet_next(r)){
        const char* account=ResultSet_getStringByName(r,"account");
        if(account==NULL){
            out["response type"]=ACCOUNT_NOT_EXISTED;
        }else{
            out["response type"]=ACCOUNT_EXISTED;
        }
    }
    return out;
}
