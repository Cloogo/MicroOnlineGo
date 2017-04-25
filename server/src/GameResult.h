#ifndef _GAMERESULT_H
#define _GAMERESULT_H

#include <redbud/parser/json_parser.h>

class GameResult{
public:
    GameResult(redbud::parser::json::Json in);
    ~GameResult(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    std::string account;
    int level;
    int integral;
};
#endif
