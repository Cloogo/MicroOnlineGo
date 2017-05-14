#ifndef _SQLSTM_H
#define _SQLSTM_H
#include <muduo/base/Logging.h>
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>
#include <redbud/parser/json_parser.h>
#include "SqlManager.h"

class SqlStm{
public:
    static inline bool isExisted(std::string stm){
        LOG_INFO<<"SqlStm:isExisted:stm:"<<stm;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            SqlManager::getInstance().putConn(sqlConn);
            return true;
        }
        SqlManager::getInstance().putConn(sqlConn);
        return false;
    }

    static inline bool silence(std::string stm){
        LOG_INFO<<"SqlStm:silence:stm:"<<stm;
        bool isOk=false;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        TRY
        {
            Connection_execute(sqlConn,stm.c_str());
            isOk=true;
        }
        CATCH(SQLException)
        {
        }
        END_TRY;
        SqlManager::getInstance().putConn(sqlConn);
        return isOk;
    }

    static inline bool getField(std::string stm,std::string name){
        bool s=false;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            s=ResultSet_getIntByName(r,name.c_str());
        }
        SqlManager::getInstance().putConn(sqlConn);
        return s;
    }

    static inline redbud::parser::json::Json getRoomList(std::string stm){
        using namespace redbud::parser::json;
        Json lst;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        while(ResultSet_next(r)){
            lst.push_back(Json::Object{
                            {"id",ResultSet_getStringByName(r,"id")},
                            {"name",ResultSet_getStringByName(r,"name")},
                            {"player1",ResultSet_getStringByName(r,"player1")},
                            {"player2",ResultSet_getStringByName(r,"player2")},
                            {"state",ResultSet_getIntByName(r,"state")},
                            {"config",Json::Object{
                                    {"komi",ResultSet_getIntByName(r,"komi")},
                                    {"mainTime",ResultSet_getIntByName(r,"mainTime")},
                                    {"period",ResultSet_getIntByName(r,"period")},
                                    {"periodTimes",ResultSet_getIntByName(r,"periodTimes")}
                                }
                             }
                         }
                        );
        }
        SqlManager::getInstance().putConn(sqlConn);
        return lst;
    }

    static inline redbud::parser::json::Json getRoom(int roomid){
        redbud::parser::json::Json room;
        std::string stm="select * from rooms where id="+std::to_string(roomid)+" limit 1";
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        TRY
        {
            ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
            if(ResultSet_next(r)){
             room["id"]=ResultSet_getIntByName(r,"id");
             room["name"]=ResultSet_getStringByName(r,"name");
             room["player1"]=ResultSet_getStringByName(r,"player1");
             room["player2"]=ResultSet_getStringByName(r,"player2");
             room["state"]=ResultSet_getIntByName(r,"state");
             room["config"]["komi"]=ResultSet_getIntByName(r,"komi");
             room["config"]["mainTime"]=ResultSet_getIntByName(r,"mainTime");
             room["config"]["period"]=ResultSet_getIntByName(r,"period");
             room["config"]["periodTimes"]=ResultSet_getIntByName(r,"periodTimes");
            }
        }
        CATCH(SQLException)
        {
            room.clear();
        }
        END_TRY;
        SqlManager::getInstance().putConn(sqlConn);
        return room;
    }

    static inline redbud::parser::json::Json getUserList(std::string stm){
        using namespace redbud::parser::json;
        Json lst;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        while(ResultSet_next(r)){
            lst.push_back(Json::Object{
                            {"account",ResultSet_getStringByName(r,"account")},
                            {"nickname",ResultSet_getStringByName(r,"nickname")},
                            {"state",ResultSet_getIntByName(r,"state")},
                            {"sex",ResultSet_getIntByName(r,"sex")},
                            {"room",ResultSet_getIntByName(r,"roomid")},
                            {"data",
                            Json::Object{
                                {"rank",ResultSet_getIntByName(r,"rank")},
                                {"level",ResultSet_getIntByName(r,"level")},
                                {"win",ResultSet_getIntByName(r,"win")},
                                {"lose",ResultSet_getIntByName(r,"lose")},
                                {"draw",ResultSet_getIntByName(r,"draw")}
                            }},
                            {"birthday",
                            Json::Object{
                                {"year",ResultSet_getIntByName(r,"year")},
                                {"month",ResultSet_getIntByName(r,"month")},
                                {"day",ResultSet_getIntByName(r,"day")},
                            }}
                            }
                            );
        }
        SqlManager::getInstance().putConn(sqlConn);
        return lst;
    }

    static inline redbud::parser::json::Json getUser(std::string account,std::string stm){
        redbud::parser::json::Json user;
        user["account"]=account;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        TRY
        {
            ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
            if(ResultSet_next(r)){
                user["nickname"]=ResultSet_getStringByName(r,"nickname");
                user["data"]["rank"]=ResultSet_getIntByName(r,"rank");
                user["data"]["level"]=ResultSet_getIntByName(r,"level");
                user["data"]["win"]=ResultSet_getIntByName(r,"win");
                user["data"]["lose"]=ResultSet_getIntByName(r,"lose");
                user["data"]["draw"]=ResultSet_getIntByName(r,"draw");
                user["state"]=ResultSet_getIntByName(r,"state");
                user["sex"]=ResultSet_getIntByName(r,"sex");
                user["birthday"]["year"]=ResultSet_getIntByName(r,"year");
                user["birthday"]["month"]=ResultSet_getIntByName(r,"month");
                user["birthday"]["day"]=ResultSet_getIntByName(r,"day");
                user["room"]=ResultSet_getIntByName(r,"roomid");
            }
        }
        CATCH(SQLException)
        {
            user.clear();
        }
        END_TRY;
        SqlManager::getInstance().putConn(sqlConn);
        return user;
    }
};
#endif
