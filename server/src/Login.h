#ifndef _LOGIN_H
#define _LOGIN_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class Login{
public:
    Login(const redbud::parser::json::Json& in);
    ~Login()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    redbud::parser::json::Json out;
    std::string account;
    std::string passwd;
    muduo::net::TcpConnectionPtr conn;
};
#endif
