#ifndef _ROOMMANAGER_H
#define _ROOMMANAGER_H
#include <pthread.h>
#include <map>
#include <set>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <redbud/parser/json.h>
#include <muduo/net/TcpConnection.h>

class RoomManager:boost::noncopyable{
public:
    typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&) > msgCb;

    static RoomManager& getInstance(){
        pthread_once(&ponce,&RoomManager::init);
        return *instance;
    }
    static void init(){
        instance=new RoomManager();
    }
    void add(const muduo::net::TcpConnectionPtr& conn,const int roomId);
    void remove(const muduo::net::TcpConnectionPtr& conn,const int roomId);
    void broadcast(const int roomId,std::string msg);
    void setCb(const msgCb& sendBack_);
    static pthread_once_t ponce;
    static RoomManager* instance;
private:
    bool find(const int roomId);
    typedef std::set<muduo::net::TcpConnectionPtr>ConnsList;
    typedef std::map<int,std::set<muduo::net::TcpConnectionPtr>>::iterator Iter;
    std::map<int,std::set<muduo::net::TcpConnectionPtr>>rooms;
    msgCb sendBack;
};
#endif
