#ifndef _GROUPCHAT_H
#define _GROUPCHAT_H
#include <redbud/parser/json_parser.h>

class GroupChat{
public:
    GroupChat(const redbud::parser::json::Json& in);
    ~GroupChat()=default;
    redbud::parser::json::Json handle();
private:
    std::string nickname;
    std::string msg;
    redbud::parser::json::Json out;
};
#endif
