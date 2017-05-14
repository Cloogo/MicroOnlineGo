#ifndef _PAIRMANAGER_H
#define _PAIRMANAGER_H
#include <pthread.h>
#include <map>
#include <set>
#include <utility>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <redbud/parser/json.h>
#include <muduo/net/TcpConnection.h>
#include "Proto.h"

class PairManager:boost::noncopyable{
public:
    using TellCli=boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&)>;
    static PairManager& getInstance(){
        pthread_once(&ponce,&PairManager::init);
        return *instance;
    }
    static void init(){
        instance=new PairManager();
    }
    void setCb(const TellCli& tellCli_);
    bool find(const int id);
    ORDER add(const muduo::net::TcpConnectionPtr& conn,const int id);
    void remove(const muduo::net::TcpConnectionPtr& conn,const int id);
    int match();
    ORDER pos(const muduo::net::TcpConnectionPtr& self,const int id);
    void singlecast(const muduo::net::TcpConnectionPtr& conn,const int id,std::string msg);
    static pthread_once_t ponce;
    static PairManager* instance;
private:
    using ConnPair=std::pair<muduo::net::TcpConnectionPtr,muduo::net::TcpConnectionPtr>;
    using ConnPairsList=std::map<int,ConnPair>;
    using Iter=ConnPairsList::iterator;
    ConnPairsList pairsList;
    TellCli tellCli;
};
#endif
