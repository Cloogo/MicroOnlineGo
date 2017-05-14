#include "Proto.h"
#include "RoomInfo.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;

RoomInfo::RoomInfo(const Json& in){
}

Json
RoomInfo::handle(){
    std::string stm="select * from rooms order by id";
    Json rlist=SqlStm::getRoomList(stm);
    if(rlist.size()!=0){
        out["rooms_list"]=rlist;
    }else{
        out["rooms_list"]=Json::Array{};
    }
    out["rooms_num"]=rlist.size();
    out["response_type"]=static_cast<int>(T::FETCH_ROOM_INFO_SUCCESS);
    return out;
}
