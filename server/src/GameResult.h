#ifndef _GAMERESULT_H
#define _GAMERESULT_H

#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class GameResult{
public:
    GameResult(const redbud::parser::json::Json& in);
    ~GameResult()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    int getField(redbud::parser::json::Json user,std::string name);
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    std::string account;
    int room_id;
};
#endif
