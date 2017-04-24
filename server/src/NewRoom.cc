#include "NewRoom.h"
#include "Proto.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;


NewRoom::NewRoom(Json in){
    id=in["id"].as_number();
    nickname=in["nickname"].as_string();
    name=in["name"].as_string();
}

Json
NewRoom::handle(){
    string stm0="insert into rooms value(+"to_string(id)+",\""+name+"\",\""+nickname+"\",\"\",\"waiting\")";
    if(SqlStm::silence(stm0)){
        in.erase("request_type");
        Json toall=in;
        toall["status"]="waiting";
        toall["response_type"]=int(T::BROADCAST_SITDOWN);
        RoomManager::getInstance().broadcast(0,toall.dumps());
        out["response_type"]=int(T::SITDOWN_SUCCESS);
        return out;
    }else{
    }
    out["response_type"]=int(T::SITDOWN_FAILED);
    out["reason"]="Inner server error";
    return out;
}
