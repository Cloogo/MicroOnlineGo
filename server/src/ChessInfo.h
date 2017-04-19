#ifndef _CHESSINFO_H
#define _CHESSINFO_H
#include <redbud/parser/json_parser.h>

class ChessInfo{
public:
    ChessInfo(Json in);
    ~ChessInfo(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    int id;
    int x;
    int y;
};
#endif
