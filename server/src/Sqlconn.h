#ifndef _SQLCONN_H
#define _SQLCONN_H

#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>
#include <zdb/URL.h>
class Sqlconn{
public:
    Sqlconn(std::string urlstr_,int maxConnsNum_){
        urlstr=urlstr_;
        maxConnsNum=maxConnsNum_;
    }
    ~Sqlconn();
    bool start();
    static Connection_T getConn();
    static void putConn(Connection_T t);
private:
    static ConnectionPool_T pool;
    URL_T url;
    std::string urlstr;
    int maxConnsNum;
};
#endif
