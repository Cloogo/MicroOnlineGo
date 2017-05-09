#ifndef _PLAYERSINFO_H
#define _PLAYERSINFO_H
#include <redbud/parser/json_parser.h>
class PlayersInfo{
public:
    PlayersInfo(const redbud::parser::json::Json& in);
    ~PlayersInfo()=default;
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
};
#endif
