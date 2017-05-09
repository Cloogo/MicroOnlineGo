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
    order=ORDER(static_cast<int>(in["order"].as_number()));
}

Json
NewRival::enter(){
    string stm0="update rooms set player2=\""+nickname+"\",readygo2=\"no\",status=\"waiting\" where id="+to_string(id);
    if(SqlStm::silence(stm0)){
        Json toall;
        toall["id"]=id;
        toall["nickname"]=nickname;
        toall["order"]=static_cast<int>(order);
        toall["status"]="waiting";
        toall["response_type"]=static_cast<int>(T::BROADCAST_SITDOWN);
        RoomManager::getInstance().broadcast(0,toall.dumps());
        out["response_type"]=static_cast<int>(T::SITDOWN_SUCCESS);
        return out;
    }
    out["response_type"]=static_cast<int>(T::SITDOWN_FAILED);
    out["reason"]="inner server error";
    return out;
}

Json
NewRival::leave(){
    string stm0;
    if(order==ORDER::LEFT){
        stm0="update rooms set player1=\"\",readygo1=\"no\",status=\"waiting\" where id="+to_string(id);
    }else if(order==ORDER::RIGHT){
        stm0="update rooms set player2=\"\",readygo2=\"no\",status=\"waiting\" where id="+to_string(id);
    }
    if(SqlStm::silence(stm0)){
        Json toall;
        toall["id"]=id;
        toall["nickname"]=nickname;
        toall["status"]="waiting";
        toall["response_type"]=static_cast<int>(T::BROADCAST_LEAVE);
        RoomManager::getInstance().broadcast(0,toall.dumps());
        out["response_type"]=static_cast<int>(T::LEAVE_SUCCESS);
        return out;
    }
    out["response_type"]=static_cast<int>(T::LEAVE_FAILED);
    out["reason"]="inner server error";
    return out;
}
