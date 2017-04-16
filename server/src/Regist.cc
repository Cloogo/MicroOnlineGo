#include "Regist.h"
#include "Proto.h"
#include "SqlManager.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;

Regist::Regist(Json in){
    username=in["username"].as_string();
    passwd=in["passwd"].as_string();
    time=in["regist_time"].as_string();
}

Json
Regist::handle(){
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    std::string sql="select * from users where name=\""+username+"\" and passwd=\""+passwd+"\"";
    ResultSet_T r=Connection_executeQuery(sqlConn,sql.c_str());
    while(ResultSet_next(r)){
        const char* name=ResultSet_getStringByName(r,"name");
        if(name==NULL){
            out["response type"]=int(T::LOGIN_FAILED);
        }else{
            out["response type"]=int(T::LOGIN_SUCCESS);
            out["reason"]="No such user";
        }
    }
    return out;
}
