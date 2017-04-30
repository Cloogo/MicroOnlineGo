#include "GoServer.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <boost/bind.hpp>

using namespace muduo;
using namespace muduo::net;

GoServer::GoServer(EventLoop* loop,const InetAddress& listenAddr)
    :server_(loop,listenAddr,"GoServer"){
    server_.setConnectionCallback(
        boost::bind(&GoServer::onConnection,this,_1));
    server_.setMessageCallback(
        boost::bind(&GoServer::receive,this,_1,_2,_3));
}

GoServer::~GoServer(){}

void
GoServer::start(){
    server_.start();
}

void
GoServer::onConnection(const TcpConnectionPtr& conn){
    LOG_INFO<<"GoServer -"<<conn->peerAddress().toIpPort()<<"->"
            <<conn->localAddress().toIpPort()<<" is "
            <<(conn->connected()?"UP":"DOWN");
    if(conn->connected()){
    }else{
    }
}

void
GoServer::receive(const TcpConnectionPtr& conn,
                 Buffer* buf,
                 Timestamp time){
    while (buf->readableBytes() >= kHeaderLen){
      const void* data = buf->peek();
      const int32_t be32 = *static_cast<const int32_t*>(data); // SIGBUS
      int32_t len = muduo::net::sockets::networkToHost32(be32);
      LOG_INFO<<"LENGTH:"<<len;
      if (len > 65536 || len < 0){
        LOG_ERROR << "Invalid length " << len;
        conn->shutdown();
        break;
      }else if (buf->readableBytes() >= len+kHeaderLen){
        buf->retrieve(kHeaderLen);
        std::string msg(buf->peek(), len);
        buf->retrieve(len);
        LOG_INFO<<"REQUEST -"<<conn->peerAddress().toIpPort()<<"->"
        <<conn->localAddress().toIpPort()<<" len: "<<len
        <<" content: "<<msg;
        PacketParser packet(conn,msg,boost::bind(&GoServer::send,this,_1,_2));
        packet.dispatch();
      }else{
        LOG_INFO<<"READABLEBYTE:"<<buf->readableBytes();
        break;
      }
    }
}

void
GoServer::send(const TcpConnectionPtr& conn,
            std::string& message){
    Buffer buf;
    buf.append(message.data(), message.size());
    int32_t len = static_cast<int32_t>(message.size());
    int32_t be32 = muduo::net::sockets::hostToNetwork32(len);
    LOG_INFO<<"RESPONSE -"<<conn->localAddress().toIpPort()<<"->"
    <<conn->peerAddress().toIpPort()<<" len: "<<len
    <<" content: "<<message;
    buf.prepend(&be32, sizeof be32);
    conn->send(&buf);
}
