#ifndef _PLAYER_H
#define _PLAYER_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

class Player{
public:
    Player(const redbud::parser::json::Json& in_);
    ~Player()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    bool notify();
    bool update();
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    std::string account;
    std::string nickname;
    std::string passwd;
    int level;
    int rank;
    int win;
    int lose;
    int draw;
    int year;
    int month;
    int day;
    int state;
    int sex;
    int roomid;
};
#endif
