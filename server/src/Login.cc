#include "Login.h"
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

Login::Login(Json in){
    account=in["account"].as_string();
    passwd=in["passwd"].as_string();
}

Json
Login::handle(){
    string stm0="select * from users where account=\""+account+"\"&&passwd=\""+passwd+"\"";
    if(SqlStm::isExisted(stm0)){
        string stm1="update users set status=\"Online\" where account=\""+account+"\"";
            if(SqlStm::silence(stm1)){
                Json user=SqlStm::getUser(stm0);
                user["response_type"]=int(T::BROADCAST_SOMEONE_UP);
                auto msg=user.dumps();
                RoomManager::getInstance().broadcast(0,msg);
                out["response_type"]=int(T::LOGIN_SUCCESS);
                return out;
            }
    }
    out["response_type"]=int(T::LOGIN_FAILED);
    out["reason"]="Incorrect username or passwd";
    return out;
}
