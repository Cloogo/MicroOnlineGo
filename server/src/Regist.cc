#include "Regist.h"
#include "Proto.h"
#include "SqlManager.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE
using namespace redbud::parser::json;
using namespace std;

Regist::Regist(const Json& in){
    account =in["account"].as_string();
    nickname=in["nickname"].as_string();
    passwd  =in["password"].as_string();
    level   =in["data"]["level"].as_number();
    rank    =in["data"]["rank"].as_number();
    win     =in["data"]["win"].as_number();
    lose    =in["data"]["lose"].as_number();
    draw    =in["data"]["draw"].as_number();
    year    =in["birthday"]["year"].as_number();
    month   =in["birthday"]["month"].as_number();
    day     =in["birthday"]["day"].as_number();
    state   =in["state"].as_number();
    sex     =in["sex"].as_bool();
    roomid  =in["room"].as_number();
//    time=in["regist_time"].as_string();
}

Json
Regist::handle(){
    string stm="insert into users values(\""
        +account+"\",\""
        +nickname+"\",\""
        +passwd+"\","
        +to_string(level)+","
        +to_string(rank)+","
        +to_string(win)+","
        +to_string(lose)+","
        +to_string(draw)+","
        +to_string(year)+","
        +to_string(month)+","
        +to_string(day)+","
        +to_string(sex)+","
        +to_string(state)+","
        +to_string(roomid)+")";
    if(SqlStm::silence(stm)){
        out["response_type"]=static_cast<int>(T::REGIST_SUCCESS);
    }else{
        out["response_type"]=static_cast<int>(T::REGIST_FAILED);
        out["reason"]="inner server error";
    }
    return out;
}
