#include "SqlManager.h"

pthread_once_t SqlManager::ponce=PTHREAD_ONCE_INIT;
SqlManager* SqlManager::instance=NULL;
std::string SqlManager::url="mysql://localhost/go?user=Cloogo&password=1234";
int SqlManager::maxConnsNum=1024;

bool
SqlManager::start(){
    url_t=URL_new(url.c_str());
    if(url_t==NULL){
        return false;
    }
    pool=ConnectionPool_new(url_t);
    ConnectionPool_setInitialConnections(pool,maxConnsNum);
    ConnectionPool_start(pool);
    return true;
}

void
SqlManager::putConn(Connection_T conn){
    ConnectionPool_returnConnection(pool,conn);
}

Connection_T
SqlManager::getConn(){
    return ConnectionPool_getConnection(pool);
}
