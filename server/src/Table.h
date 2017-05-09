#ifndef _TABLE_H
#define _TABLE_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

enum class ACTION{
    IN,
    OUT
};

class Table{
public:
    Table(const redbud::parser::json::Json& in);
    ~Table()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    bool enter();
    bool leave();
    bool notify();
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    std::string account;
    ACTION action;
    int roomid;
};
#endif
