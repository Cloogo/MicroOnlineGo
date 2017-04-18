#ifndef _ROOMINFO_H
#define _ROOMINFO_H
#include <redbud/parser/json_parser.h>

class RoomInfo{
public:
    RoomInfo(redbud::parser::json::Json in);
    ~RoomInfo(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
};
#endif
