#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <redbud/parser/json_parser.h>

class Account{
public:
    Account(redbbud::parser::json::Json in);
    ~Account(){}
    redbud::parser::json::Json check();
private:
    redbud::parser::json::Json out;
    std::string account;
};
#endif
