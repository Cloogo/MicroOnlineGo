#ifndef _SQLMANAGER_H
#define _SQLMANAGER_H

#include <iostream>
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
    bool start();
    void putConn(Connection_T conn);
    Connection_T getConn();
private:
    static pthread_once_t ponce;
    static SqlManager* instance;
    static std::string url;
    static int maxConnsNum;
    URL_T url_t;
    ConnectionPool_T pool;
};
#endif
