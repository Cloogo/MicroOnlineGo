#include "PlayersInfo.h"
#include "Proto.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

PlayersInfo::PlayersInfo(Json in){
}

Json
PlayersInfo::handle(){
    std::string stm0="select count(*) from users where status!=\"Offline\"";
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    ResultSet_T r0=Connection_executeQuery(sqlConn,stm0.c_str());
    if(ResultSet_next(r0)){
        out["players_num"]=ResultSet_getInt(r0,1);
    }
    std::string stm1="select * from users where status!=\"Offline\"";
    ResultSet_T r1=Connection_executeQuery(sqlConn,stm1.c_str());
    Json plist;
    while(ResultSet_next(r1)){
        plist.push_back(Json::Object{
                        {"account",ResultSet_getStringByName(r1,"account")},
                        {"nickname",ResultSet_getStringByName(r1,"nickname")},
                        {"level",ResultSet_getIntByName(r1,"level")},
                        {"integral",ResultSet_getIntByName(r1,"integral")},
                        {"status",ResultSet_getStringByName(r1,"status")}
                        }
                        );
    }
    if(plist.size()!=0){
        out["players_list"]=plist;
    }
    out["response_type"]=int(T::FETCH_PLAYERS_INFO_SUCCESS);
    SqlManager::getInstance().putConn(sqlConn);
    return out;
}
