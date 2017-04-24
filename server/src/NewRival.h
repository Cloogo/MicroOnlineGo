#ifndef _NEWRIVAL_H
#define _NEWRIVAL_H
#include <redbud/parser/json_parser.h>

class NewRival{
public:
    NewRival(redbud::parser::json in);
    ~NewRival(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string nickname;
    int id;
};
#endif
