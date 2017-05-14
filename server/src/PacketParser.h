#ifndef _PACKETPARSER_H
#define _PACKETPARSER_H
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <muduo/net/TcpConnection.h>
#include <redbud/parser/json.h>
#include "RoomManager.h"
#include "PairManager.h"

class PacketParser:boost::noncopyable{
public:
    using TellCli=boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  std::string&)>;
    PacketParser(const muduo::net::TcpConnectionPtr& conn_,
                          const std::string msg_,
                          const TellCli& tellCli_):conn(conn_),msg(msg_),tellCli(tellCli_){
            RoomManager::getInstance().setCb(tellCli_);
            PairManager::getInstance().setCb(tellCli_);
    }

    ~PacketParser()=default;

    void dispatch();

    void encode();

    void decode();
private:
    TellCli tellCli;
    const muduo::net::TcpConnectionPtr conn;
    std::string msg;
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
};
#endif
