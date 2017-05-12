#include "GameResult.h"
#include "Proto.h"
#include "SqlStm.h"
#include "PairManager.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;
using namespace muduo::net;
using namespace std;

GameResult::GameResult(const Json& in){
    roomid=in["room_id"].as_number();
    player1point=in["point1"].as_number();
    player2point=in["point2"].as_number();
    result=RESULT_TYPE(static_cast<int>(in["result"].as_number()));
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
    switch(result){
        case RESULT_TYPE::WIN:
        {
            torival["result"]=static_cast<int>(RESULT_TYPE::LOSE);
        }
        break;
        case RESULT_TYPE::LOSE:
        {
            torival["result"]=static_cast<int>(RESULT_TYPE::WIN);
        }
        break;
    }
    torival["score"]=player2point;
    torival["response_type"]=static_cast<int>(T::SINGLECAST_UPDATE_GAMERESULT);
    PairManager::getInstance().singlecast(conn,roomid,torival.dumps());
    out["result"]=static_cast<int>(result);
    out["score"]=player1point;
//    out["response_type"]=static_cast<int>(T::UPDATE_GAMERESULT_SUCCESS);
    out["response_type"]=static_cast<int>(T::SINGLECAST_UPDATE_GAMERESULT);
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

