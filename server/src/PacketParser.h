#ifndef _PACKETPARSER_H
#define _PACKETPARSER_H
#include "RoomManager.h"
#include "PairManager.h"
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <muduo/net/TcpConnection.h>
#include <redbud/parser/json.h>

class PacketParser:boost::noncopyable{
public:
    using msgCb=boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&)>;
    PacketParser(const muduo::net::TcpConnectionPtr& conn_,
                          const std::string msg_,
                          const msgCb& msgCb_):conn(conn_),msg(msg_),sendBack(msgCb_){
            RoomManager::getInstance().setCb(msgCb_);
            PairManager::getInstance().setCb(msgCb_);
    }

    ~PacketParser()=default;

    void dispatch();

    void encode();

    void decode();
private:
    msgCb sendBack;
    const muduo::net::TcpConnectionPtr conn;
    std::string msg;
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
};
#endif
