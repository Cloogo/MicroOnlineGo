#ifndef _ROOM_H
#define _ROOM_H
#include <redbud/parser/json_parser.h>
#include <muduo/net/TcpConnection.h>

enum class PLAYER_ACTION{
    PLAYER1IN=0,
    PLAYER2IN,
    PLAYER1OUT,
    PLAYER2OUT,
    DESTROY
};

class Room{
public:
    Room(const redbud::parser::json::Json& in);
    ~Room()=default;
    redbud::parser::json::Json handle();
    void setConn(const muduo::net::TcpConnectionPtr& conn_);
private:
    bool destroy();
    redbud::parser::json::Json in;
    redbud::parser::json::Json out;
    muduo::net::TcpConnectionPtr conn;
    PLAYER_ACTION action;
    int roomid;
    std::string name;
    std::string player1;
    std::string player2;
    int state;
    int komi;
    int mainTime;
    int period;
    int periodTimes;
};
#endif
