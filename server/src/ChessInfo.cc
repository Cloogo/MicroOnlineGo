#include "ChessInfo.h"
#include "Proto.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

ChessInfo::ChessInfo(Json in){
}

Json
ChessInfo::handle(){
    out["response_type"]=int(T::PLACECHESS_SUCCESS);
    return out;
}
