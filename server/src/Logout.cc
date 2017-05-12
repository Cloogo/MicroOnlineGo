#include "Logout.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace std;

Logout::Logout(const Json& in){
    account=in["account"].as_string();
}

Json
Logout::handle(){
    string stm0="update users set state="+to_string(static_cast<int>(STATE::OUTLINE))+" where account=\""+account+"\"";
    if(SqlStm::silence(stm0)){
        Json user;
        user["account"]=account;
//        user["response_type"]=static_cast<int>(T::BROADCAST_SOMEONE_DOWN);
        user["response_type"]=static_cast<int>(T::LOGOUT_SUCCESS);
        auto msg=user.dumps();
        RoomManager::getInstance().broadcast(0,msg);
//        out["response_type"]=static_cast<int>(T::LOGOUT_SUCCESS);
        return out;
    }
    out["response_type"]=static_cast<int>(T::LOGOUT_FAILED);
    out["reason"]="inner server error";
    return out;
}
