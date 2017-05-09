#ifndef _ROOMINFO_H
#define _ROOMINFO_H
#include <redbud/parser/json_parser.h>

class RoomInfo{
public:
    RoomInfo(const redbud::parser::json::Json& in);
    ~RoomInfo()=default;
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
};
#endif
