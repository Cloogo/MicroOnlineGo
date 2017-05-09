#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <redbud/parser/json_parser.h>

class Account{
public:
    Account(const redbud::parser::json::Json& in);
    ~Account()=default;
    redbud::parser::json::Json handle();
    redbud::parser::json::Json check();
private:
    redbud::parser::json::Json out;
    std::string account;
};
#endif
