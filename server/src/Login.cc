#include "Login.h"
#include "Proto.h"
#include "SqlManager.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define SETTYPE(T) out["response type"]=int(RESPONSE_TYPE::T)

using namespace redbud::parser::json;

Login::Login(Json in){
    username=in["username"].as_string();
    passwd=in["passwd"].as_string();
}

redbud::parser::json::Json
Login::handle(){
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    std::string sql="select * from users where username=\""+username+"\" and passwd=\""+passwd+"\"";
    ResultSet_T r=Connection_executeQuery(sqlConn,sql.c_str());
    if(ResultSet_next(r)){
        SETTYPE(LOGIN_SUCCESS);
    }else{
        SETTYPE(LOGIN_FAILED);
        out["reason"]="Incorrect username or passwd";
    }
    return out;
}
