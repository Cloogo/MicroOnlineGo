#ifndef _REGIST_H
#define _REGIST_H
#include <redbud/parser/json_parser.h>

class Regist{
public:
    Regist(const redbud::parser::json::Json& in);
    ~Regist()=default;
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
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
//    std::string time;
};
#endif
