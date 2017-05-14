#ifndef _GROUPCHAT_H
#define _GROUPCHAT_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class GroupChat{
public:
    GroupChat(const redbud::parser::json::Json& in);
    ~GroupChat()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    std::string account;
    std::string msg;
};
#endif
