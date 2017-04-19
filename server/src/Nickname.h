#ifndef _NICKNAME_H
#define _NICKNAME_H

#include <redbud/parser/json_parser.h>

class Nickname{
public:
    Nickname(redbud::parser::json::Json in);
    ~Nickname(){}
    redbud::parser::json::Json handle();
    redbud::parser::json::Json check();
private:
    redbud::parser::json::Json out;
    std::string nickname;
};
#endif
