#ifndef _HANDSHAKE_H
#define _HANDSHAKE_H
#include <redbud/parser/json_parser.h>

class Handshake{
public:
    Handshake(redbud::parser::json::Json in);
    ~Handshake(){}
    redbud::parser::json::Json handle();
private:
    redbud::parser::json::Json out;
    int id;
    std::string nickname;
};
#endif
