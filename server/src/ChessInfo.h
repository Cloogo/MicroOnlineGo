#ifndef _CHESSINFO_H
#define _CHESSINFO_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class ChessInfo{
public:
    ChessInfo(const redbud::parser::json::Json& in);
    ~ChessInfo()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    redbud::parser::json::Json in;
    redbud::parser::json::Json torival;
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
};
#endif
