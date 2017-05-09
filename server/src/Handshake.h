#ifndef _HANDSHAKE_H
#define _HANDSHAKE_H
#include "Proto.h"
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class Handshake{
public:
    Handshake(const redbud::parser::json::Json& in);
    ~Handshake()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    int roomid;
    bool player1Ready;
    bool player2Ready;
};
#endif
