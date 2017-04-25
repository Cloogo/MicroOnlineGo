#ifndef _SQLSTM_H
#define _SQLSTM_H
#include "SqlManager.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>
#include <redbud/parser/json_parser.h>

class SqlStm{
public:
    static bool isExisted(std::string stm){
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            SqlManager::getInstance().putConn(sqlConn);
            return true;
        }
        return false;
    }
    static bool silence(std::string stm){
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
    static std::string getField(std::string stm,std::string name){
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            std::string s(ResultSet_getStringByName(r,name.c_str()));
            return s;
        }
        return "";
    }

    static redbud::parser::json::Json getUser(std::string stm){
        redbud::parser::json::Json user;
        Connection_T sqlConn=SqlManager::getInstance().getConn();
        ResultSet_T r=Connection_executeQuery(sqlConn,stm.c_str());
        if(ResultSet_next(r)){
            user["nickname"]=ResultSet_getStringByName(r,"nickname");
            user["level"]=ResultSet_getIntByName(r,"level");
            user["integral"]=ResultSet_getIntByName(r,"integral");
            user["status"]=ResultSet_getStringByName(r,"status");
        }
        SqlManager::getInstance().putConn(sqlConn);
        return user;
    }
};
#endif
