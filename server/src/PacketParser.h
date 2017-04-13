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
    explicit PacketParser(const TcpConnectionPtr& conn_,
                          const std::string msg_,
                          const msgCb& msgCb_):conn(conn_),msg(msg_),msgCb(msgCb_){
    }

    ~PacketParser(){}

    void dispatch();

    void encode();

    void decode();
private:
    msgCb msgCb;
    const muduo::net::TcpConnectionPtr conn;
    std::string msg;
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
};
#endif
