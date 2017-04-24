#ifndef _NEWRIVAL_H
#define _NEWRIVAL_H
#include "Proto.h"
#include <redbud/parser/json_parser.h>

class NewRival{
public:
    NewRival(redbud::parser::json in);
    ~NewRival(){}
    redbud::parser::json::Json enter();
    redbud::parser::json::Json leave();
private:
    redbud::parser::json::Json out;
    std::string nickname;
    int id;
    ORDER order;
};
#endif
