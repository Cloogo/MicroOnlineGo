#include "Logout.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace std;

Logout::Logout(Json in){
    account=in["account"].as_string();
}

Json
Logout::handle(){
    string stm0="update users set status=\"Offline\" where account=\""+account+"\"";
    if(SqlStm::silence(stm0)){
        Json user=SqlStm::getUser(stm0);
        user["response_type"]=int(T::BROADCAST_SOMEONE_DOWN);
        auto msg=user.dumps();
        RoomManager::getInstance().broadcast(0,msg);
        out["response_type"]=int(T::LOGOUT_SUCCESS);
        return out;
    }
    out["response_type"]=int(T::LOGOUT_FAILED);
    out["reason"]="inner server error";
    return out;
}
