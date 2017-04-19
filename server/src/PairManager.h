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

class PairManager:boost::noncopyable{
public:
    typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&)>msgCb;
    static PairManager& getInstance(){
        pthread_once(&ponce,&PairManager::init);
        return *instance;
    }
    static void init(){
        instance=new PairManager();
    }
    void add(const muduo::net::TcpConnectionPtr& conn,const int id);
    void remove(const muduo::net::TcpConnectionPtr& conn,const int id);
    int match();
    void singlecast(const muduo::net::TcpConnectionPtr& conn,const int id,std::string msg);
    static pthread_once_t ponce;
    static PairManager* instance;
private:
    typedef std::pair<muduo::net::TcpConnectionPtr,muduo::net::TcpConnectionPtr>>ConnPair;
    typedef std::map<int,ConnPair>ConnPairsList;
    typedef ConnPairsList::iterator Iter;
    ConnPairsList pairsList;
    msgCb sendBack;
};
#endif
