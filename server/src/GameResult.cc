#include "GameResult.h"
#include "Proto.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace muduo::net;
using namespace std;

GameResult::GameResult(const Json& in){
    account=in["account"].as_string();
    room_id=in["room_id"].as_number();
}

Json
GameResult::handle(){
#if 0
    string stm0="select * from users where account=\""+account+"\" limit 1";
    Json user=SqlStm::getUser(account,stm0);
    string stm1="update users set "
        "lose="+to_string(getField(user,"lose")+1)
        +" where account=\""+account+"\"";
    if(SqlStm::silence(stm1)){
        string stm2="update users set "
            "win="+to_string()
        out["response_type"]=static_cast<int>(T::UPDATE_GAMERESULT_SUCCESS);
    }else{
        out["response_type"]=static_cast<int>(T::UPDATE_GAMERESULT_FAILED);
    }
    return out;
#endif
    Json torival;
    torival["response_type"]=static_cast<int>(T::SINGLECAST_UPDATE_GAMERESULT);
    out["response_type"]=static_cast<int>(T::UPDATE_GAMERESULT_SUCCESS);
    return out;
}

int
GameResult::getField(Json user,string name){
    return user[name].as_number();
}

void
GameResult::setConn(const TcpConnectionPtr& conn_){
    conn=conn_;
}

