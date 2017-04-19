#ifndef _SINGLECASTMSG_H
#define _SINGLECASTMSG_H
#include <redbud/parser/json_parser.h>

class SinglecastMsg{
public:
    SinglecastMsg(redbud::parser::json::Json in);
    ~SinglecastMsg(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string nickname;
    std::string msg;
};
#endif
