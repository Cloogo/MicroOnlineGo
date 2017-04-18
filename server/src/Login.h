#ifndef _LOGIN_H
#define _LOGIN_H
#include <redbud/parser/json_parser.h>

class Login{
public:
    Login(redbud::parser::json::Json in);
    ~Login(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string account;
    std::string passwd;
};
#endif
