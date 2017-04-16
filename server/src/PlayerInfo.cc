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
    username=in["username"].as_string();
}

redbud::parser::json::Json
PlayerInfo::handle(){
    std::string stm="select * from users where name=\""+username+"\"";
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
    if(ResultSet_next(r)){
        out["response type"]=int(T::FETCH_PLAYER_INFO_SUCCESS);
        out["username"]=username;
        out["title"]=ResultSet_getStringByName(r,"title");
        out["level"]=ResultSet_getIntByName(r,"level");
        out["integral"]=ResultSet_getIntByName(r,"integral");
        out["winning_probability"]=ResultSet_getDoubleByName(r,"winning_probability");
    }else{
        out["response type"]=int(T::FETCH_PLAYER_INFO_FAILED);
        out["reason"]="inner server error";
    }
    SqlManager::getInstance().getConn().putConn(sqlConn);
    return out;
}
