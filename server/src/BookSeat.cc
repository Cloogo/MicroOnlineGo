#include "BookSeat.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;
using namespace std;
using namespace muduo::net;

BookSeat::BookSeat(const Json& in){
    id=in["room_id"].as_number();
    account=in["player"].as_string();
}

Json
BookSeat::handle(){
    string stm0="select * from rooms where id="+to_string(id)+" limit 1";
    if(SqlStm::getField(stm0,"state")==int(ROOM_STATE::WAITING)){
        out["response_type"]=static_cast<int>(T::SITDOWN_SUCCESS);
        return out;
    }
    out["response_type"]=static_cast<int>(T::SITDOWN_FAILED);
    out["reason"]="inner server error";
    return out;
}

void
BookSeat::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}
