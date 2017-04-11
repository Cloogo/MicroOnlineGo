#ifndef _PACKETPARSER_H
#define _PACKETPARSER_H
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <muduo/net/TcpConnection.h>
#include <redbud/parser/json.h>

class PacketParser:boost::noncopyable{
public:
    typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&)> msgCb;
    explicit PacketParser(const std::string msg,
                          const msgCb& msgCb):msg_(msg),msgCb_(msgCb){
    }

    ~PacketParser(){}

    void dispatch();

    void encode();

    void decode();
private:
    msgCb msgCb_;
    std::string msg_;
    Entrance entrance_;
};
#endif
