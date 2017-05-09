#ifndef _SINGLECASTMSG_H
#define _SINGLECASTMSG_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class SinglecastMsg{
public:
    SinglecastMsg(const redbud::parser::json::Json& in);
    ~SinglecastMsg()=default;
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    redbud::parser::json::Json torival;
    muduo::net::TcpConnectionPtr conn;
    int roomid;
    std::string nickname;
    std::string msg;
};
#endif
