#include "RoomInfo.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define T RESPONSE_TYPE
using namespace redbud::parser::json;

RoomInfo::RoomInfo(const Json& in){
}

Json
RoomInfo::handle(){
    std::string stm0="select count(*) from rooms";
    Connection_T sqlConn=SqlManager::getInstance().getConn();
    ResultSet_T r0=Connection_executeQuery(sqlConn,stm0.c_str());
    if(ResultSet_next(r0)){
        out["rooms_num"]=ResultSet_getInt(r0,1);
    }
    std::string stm1="select * from rooms order by id";
    ResultSet_T r1=Connection_executeQuery(sqlConn,stm1.c_str());
    Json rlist;
    while(ResultSet_next(r1)){
        rlist.push_back(Json::Object{
                        {"id",ResultSet_getStringByName(r1,"id")},
                        {"name",ResultSet_getStringByName(r1,"name")},
                        {"player1",ResultSet_getStringByName(r1,"player1")},
                        {"player2",ResultSet_getStringByName(r1,"player2")},
                        {"state",ResultSet_getIntByName(r1,"state")},
                        {"Config",
                        Json::Object{
                            {"komi",ResultSet_getIntByName(r1,"komi")},
                            {"mainTime",ResultSet_getIntByName(r1,"mainTime")},
                            {"period",ResultSet_getIntByName(r1,"period")},
                            {"periodTimes",ResultSet_getIntByName(r1,"periodTimes")}
                        }
                        }
                        }
                        );
    }
    if(rlist.size()!=0){
        out["rooms_list"]=rlist;
    }
    out["response_type"]=static_cast<int>(T::FETCH_ROOM_INFO_SUCCESS);
    SqlManager::getInstance().putConn(sqlConn);
    return out;
}
