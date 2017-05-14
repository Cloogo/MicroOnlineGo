#include "Proto.h"
#include "PlayersInfo.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE
using namespace std;
using namespace redbud::parser::json;

PlayersInfo::PlayersInfo(const Json& in){
}

Json
PlayersInfo::handle(){
    string stm="select * from users where state!="+to_string(static_cast<int>(STATE::OUTLINE));
    Json plist=SqlStm::getUserList(stm);
    if(plist.size()!=0){
        out["players_list"]=plist;
    }
    out["players_num"]=plist.size();
    out["response_type"]=static_cast<int>(T::FETCH_PLAYERS_INFO_SUCCESS);
    return out;
}
