#include "PlayerInfo.h"
#include "Proto.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

PlayerInfo::PlayerInfo(const Json& in){
    account=in["account"].as_string();
}

Json
PlayerInfo::handle(){
    std::string stm="select * from users where account=\""+account+"\"";
    Json user=SqlStm::getUser(account,stm);
    if(!user.empty()){
        out["user"]=user;
        out["response_type"]=static_cast<int>(T::FETCH_PLAYER_INFO_SUCCESS);
    }else{
        out["response_type"]=static_cast<int>(T::FETCH_PLAYER_INFO_FAILED);
        out["reason"]="inner server error";
    }
    return out;
}
