#ifndef _REGIST_H
#define _REGIST_H
#include <redbud/parser/json_parser.h>

class Regist{
public:
    Regist(redbud::parser::json::Json in);
    ~Regist(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string username;
    std::string passwd;
    std::string time;
};
#endif
