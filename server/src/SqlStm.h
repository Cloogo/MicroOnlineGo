#ifndef _SQLSTM_H
#define _SQLSTM_H
#include "SqlManager.h"
#include <muduo/base/Logging.h>
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>
#include <redbud/parser/json_parser.h>

class SqlStm{
public:

    static bool isExisted(std::string stm){
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

    static bool silence(std::string stm){
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

    static bool getField(std::string stm,std::string name){
        bool s=false;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            s=ResultSet_getIntByName(r,name.c_str());
        }
        SqlManager::getInstance().putConn(sqlConn);
        return s;
    }

    static redbud::parser::json::Json getRoom(int roomid){
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
             room["Config"]["komi"]=ResultSet_getIntByName(r,"komi");
             room["Config"]["mainTime"]=ResultSet_getIntByName(r,"mainTime");
             room["Config"]["period"]=ResultSet_getIntByName(r,"period");
             room["Config"]["periodTimes"]=ResultSet_getIntByName(r,"periodTimes");
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
    static redbud::parser::json::Json getUser(std::string account,std::string stm){
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
