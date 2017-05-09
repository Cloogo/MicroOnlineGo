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
using namespace std;

PlayersInfo::PlayersInfo(const Json& in){
}

Json
PlayersInfo::handle(){
    string stm0="select count(*) from users where state!="+to_string(static_cast<int>(STATE::OUTLINE));
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    ResultSet_T r0=Connection_executeQuery(sqlConn,stm0.c_str());
    if(ResultSet_next(r0)){
        out["players_num"]=ResultSet_getInt(r0,1);
    }
    string stm1="select * from users where state!="+to_string(static_cast<int>(STATE::OUTLINE));
    ResultSet_T r1=Connection_executeQuery(sqlConn,stm1.c_str());
    Json plist;
    while(ResultSet_next(r1)){
        plist.push_back(Json::Object{
                        {"account",ResultSet_getStringByName(r1,"account")},
                        {"nickname",ResultSet_getStringByName(r1,"nickname")},
                        {"state",ResultSet_getIntByName(r1,"state")},
                        {"sex",ResultSet_getIntByName(r1,"sex")},
                        {"room",ResultSet_getIntByName(r1,"roomid")},
                        {"data",
                        Json::Object{
                            {"rank",ResultSet_getIntByName(r1,"rank")},
                            {"level",ResultSet_getIntByName(r1,"level")},
                            {"win",ResultSet_getIntByName(r1,"win")},
                            {"lose",ResultSet_getIntByName(r1,"lose")},
                            {"draw",ResultSet_getIntByName(r1,"draw")}
                        }},
                        {"birthday",
                        Json::Object{
                            {"year",ResultSet_getIntByName(r1,"year")},
                            {"month",ResultSet_getIntByName(r1,"month")},
                            {"day",ResultSet_getIntByName(r1,"day")},
                        }}
                        }
                        );
    }
    if(plist.size()!=0){
        out["players_list"]=plist;
    }
    out["response_type"]=static_cast<int>(T::FETCH_PLAYERS_INFO_SUCCESS);
    SqlManager::getInstance().putConn(sqlConn);
    return out;
}
