#include "PlayerInfo.h"
#include "Proto.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

PlayerInfo::PlayerInfo(Json in){
    account=in["account"].as_string();
}

Json
PlayerInfo::handle(){
    std::string stm="select * from users where account=\""+account+"\"";
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
    if(ResultSet_next(r)){
        out["response_type"]=int(T::FETCH_PLAYER_INFO_SUCCESS);
        out["account"]=account;
        out["level"]=ResultSet_getIntByName(r,"level");
        out["integral"]=ResultSet_getIntByName(r,"integral");
        out["status"]=ResultSet_getStringByName(r,"status");
    }else{
        out["response_type"]=int(T::FETCH_PLAYER_INFO_FAILED);
        out["reason"]="inner server error";
    }
    SqlManager::getInstance().putConn(sqlConn);
    return out;
}
