#ifndef _NEWROOM_H
#define _NEWROOM_H
#include <redbud/parser/json_parser.h>

class NewRoom{
public:
    NewRoom(redbud::parser::json::Json in);
    ~NewRoom(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    int id;
    std::string nickname;
    std::string name;
};
#endif
