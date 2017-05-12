#ifndef _GAMERESULT_H
#define _GAMERESULT_H

#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

enum class RESULT_TYPE{
    WIN=0,
    LOSE=1,
    DRAW=2,
    PLAYER1_OVERTIME=3,
    PLAYER2_OVERTIME=4,
    PLAYER1_SURRENDER=5,
    PLAYER2_SURRENDER=6,
    PLAYER1_ESCAPE=7,
    PLAYER2_ESCAPE=8
};

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
    int roomid;
    double player1point;
    double player2point;
    RESULT_TYPE result;
};
#endif
