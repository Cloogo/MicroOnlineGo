#include "ChessInfo.h"
#include "Proto.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

ChessInfo::ChessInfo(Json in){
}

Json
ChessInfo::handle(){
    in.erase("request_type");
    out=in;
    out["response_type"]=int(T::PLAYCHESS_SUCCESS);
    return out;
}
