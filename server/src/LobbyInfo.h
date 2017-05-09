#ifndef _LOBBYINFO_H
#define _LOBBYINFO_H
#include <redbud/parser/json_parser.h>
class LobbyInfo{
public:
    LobbyInfo(const redbud::parser::json::Json& in);
    ~LobbyInfo()=default;
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
};
#endif
