#ifndef _BOOKSEAT_H
#define _BOOKSEAT_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class BookSeat{
public:
    BookSeat(const redbud::parser::json::Json& in);
    ~BookSeat()=default;
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    std::string account;
    int id;
};
#endif
