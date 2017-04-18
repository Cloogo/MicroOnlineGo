#ifndef _PLAYERINFO_H
#define _PLAYERINFO_H
#include <redbud/parser/json_parser.h>
class PlayerInfo{
public:
    PlayerInfo(redbud::parser::json::Json in);
    ~PlayerInfo(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string account;
};
#endif
