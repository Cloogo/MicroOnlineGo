#ifndef _SQLMANAGER_H
#define _SQLMANAGER_H

#include <pthread.h>
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>
#include <zdb/URL.h>
#include <boost/noncopyable.hpp>

class SqlManager:boost::noncopyable{
public:
    static SqlManager& getInstance(){
        pthread_once(&ponce,&SqlManager::init);
        return *instance;
    }
    static void init(){
        instance=new SqlManager();
    }
    bool start(){
        url_t=URL_new(url.c_str());
        if(url_t==NULL){
            return false;
        }
        pool=ConnectionPool_new(url_t);
        ConnectionPool_setInitialConnections(pool,maxConnsNum);
        ConnectionPool_start(pool);
        return true;
    }
    void putConn(Connection_T conn){
        ConnectionPool_returnConnection(pool,conn);
    }

    Connection_T getConn(){
        return ConnectionPool_getConnection(pool);
    }

private:
    static pthread_once_t ponce;
    static SqlManager* instance;
    static std::string url;
    static int maxConnsNum;
    URL_T url_t;
    ConnectionPool_T pool;
};
#endif
