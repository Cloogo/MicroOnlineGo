#include "ChessInfo.h"
#include "Proto.h"
#include "PairManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace muduo::net;

ChessInfo::ChessInfo(const Json& in_){
    in=in_;
}

Json
ChessInfo::handle(){
    in.erase("request_type");
    torival=in;
    torival["response_type"]=static_cast<int>(T::SINGLECAST_PLACECHESS);
    PairManager::getInstance().singlecast(conn,in["room_id"].as_number(),torival.dumps());
//    out["response_type"]=static_cast<int>(T::PLACECHESS_SUCCESS);
//    out["response_type"]=static_cast<int>(T::SINGLECAST_PLACECHESS);
    return out;
}

void 
ChessInfo::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
