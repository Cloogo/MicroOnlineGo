#include "Login.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include "RoomManager.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;
using namespace std;

Login::Login(const Json& in){
    account=in["account"].as_string();
    passwd=in["password"].as_string();
}

Json
Login::handle(){
    string stm0="select * from users where "
                "account=\""+account+
                "\"&&passwd=\""+passwd+"\"";
    if(SqlStm::isExisted(stm0)){
        string stm1="update users set state="+to_string(static_cast<int>(STATE::IDLE))+" where account=\""+account+"\"";
            if(SqlStm::silence(stm1)){
                Json user=SqlStm::getUser(account,stm0);
                if(!user.empty()){
                    Json toall;
                    toall["user"]=user;
                    toall["response_type"]=static_cast<int>(T::BROADCAST_SOMEONE_UP);
                    auto msg=toall.dumps();
                    RoomManager::getInstance().broadcast(0,msg);
                    out["response_type"]=static_cast<int>(T::LOGIN_SUCCESS);
                    out["user"]=user;
                    return out;
                }
            }
    }
    out["response_type"]=static_cast<int>(T::LOGIN_FAILED);
    out["reason"]="Incorrect username or passwd";
    return out;
}
