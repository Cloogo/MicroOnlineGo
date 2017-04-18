#ifndef _LOGOUT_H
#define _LOGOUT_H
#include <redbud/parser/json_parser.h>

class Logout{
public:
    Logout(redbud::parser::json::Json in);
    ~Logout(){}
    redbud::parser::json::Json handle();
private:
    std::string account;
    redbud::parser::json::Json out;
};
#endif
