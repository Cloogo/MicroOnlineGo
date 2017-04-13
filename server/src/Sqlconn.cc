#include "Sqlconn.h"

Sqlconn::~Sqlconn(){
    ConnectionPool_stop(pool);
    ConnectionPool_free(&pool);
    URL_free(&url);
}

bool
Sqlconn::start(){
    url=URL_new(urlstr);
    if(url==NULL){
        return false;
    }
    pool=ConnectionPool_new(url);
    ConnectionPool_setInitialConnections(pool,maxConnsNum);
    ConnectionPool_start(pool);
    return true;
}

static Connection_T
Sqlconn::getConn(){
    return ConnectionPool_getConnection(pool);
}

static void
Sqlconn::putConn(Connection_T conn){
    Connection_returnConnection(pool,conn);
}
