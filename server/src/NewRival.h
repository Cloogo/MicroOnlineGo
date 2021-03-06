#ifndef _NEWRIVAL_H
#define _NEWRIVAL_H
#include <redbud/parser/json_parser.h>

class NewRival{
public:
    NewRival(redbud::parser::json::Json in);
    ~NewRival(){}
    redbud::parser::json::Json enter();
    redbud::parser::json::Json leave();
private:
    redbud::parser::json::Json out;
    std::string account;
    int id;
    Order order;
};
#endif
