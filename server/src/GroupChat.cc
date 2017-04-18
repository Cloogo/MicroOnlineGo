#include "GroupChat.h"
#include "RoomManager.h"
#include "Proto.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

GroupChat::GroupChat(Json in){
    nickname=in["nickname"].as_string();
    msg=in["msg"].as_string();
}

Json
GroupChat::handle(){
    Json msgtoall;
    msgtoall["response_type"]=int(T::GROUP_CHAT_MSG);
    msgtoall["nickname"]=nickname;
    msgtoall["msg"]=msg;
    RoomManager::getInstance().broadcast(0,msgtoall.dumps());
    out["response_type"]=int(T::GROUP_CHAT_SUCCESS);
    return out;
}
