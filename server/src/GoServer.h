#ifndef _GOSERVER_H
#define _GOSERVER_H

#include <muduo/net/TcpServer.h>
#include <boost/noncopyable.hpp>
#include "PacketParser.h"


class GoServer:boost::noncopyable{
public:
    GoServer(muduo::net::EventLoop* loop,
             const muduo::net::InetAddress& listenAddr);

    ~GoServer();

    void start();

    void onConnection(const muduo::net::TcpConnectionPtr& conn);

    void receive(const muduo::net::TcpConnectionPtr& conn,
                   muduo::net::Buffer* buf,
                   muduo::Timestamp time);
    
     void send(const muduo::net::TcpConnectionPtr& conn,
            std::string& message);
   

private:

    muduo::net::TcpServer server;
    const static size_t kHeaderLen = sizeof(int32_t);
};

#endif
