#ifndef _ROOMMANAGER_H
#define _ROOMMANAGER_H
#include <map>
#include <set>
#include <muduo/net/TcpConnection.h>

class RoomManager{
public:
    RoomManager();
    ~RoomManager();
    void add(const muduo::net::TcpConnectionPtr& conn,const int roomId);
    void remove(const muduo::net::TcpConnectionPtr& conn,const int roomId);
    void broadcast(const int roomId,std::string msg);
private:
    bool find(const int roomId);
    typedef std::set<muduo::net::TcpConnectionPtr>ConnsList;
    typedef std::map<int,std::set<muduo::net::TcpConnectionPtr>>::iterator Iter;
    std::map<int,std::set<muduo::net::TcpConnectionPtr>>rooms_;
};
#endif
