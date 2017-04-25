#include "ChessInfo.h"
#include "Proto.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

ChessInfo::ChessInfo(Json in){
    id=int(in["id"].as_number());
    x=int(in["x"].as_number());
    y=int(in["y"].as_number());
}

Json
ChessInfo::handle(){
    out["id"]=id;
    out["x"]=x;
    out["y"]=y;
    out["response_type"]=int(T::PLACECHESS_SUCCESS);
    return out;
}
