#include "NewRival.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;
using namespace std;

NewRival::NewRival(Json in){
    id=in["id"].as_number();
    nickname=in["nickname"].as_string();
}

Json
NewRival::handle(){
    string stm0="update rooms set player2=\""+nickname+"\",status=\"onbattle\" where id="+to_string(id);
    if(SqlStm::silence(stm1)){
        in.erase("request_type");
        Json toall=in;
        toall["status"]="waiting";
        toall["response_type"]=int(T::BROADCAST_SITDOWN);
        RoomManager::getInstance().broadcast(0,toall.dumps());
        out["response_type"]=int(T::SITDOWN_SUCCESS);
        return out;
    }
    out["response_type"]=int(T::SITDOWN_FAILED);
    out["reason"]="inner server error";
    return out;
}
