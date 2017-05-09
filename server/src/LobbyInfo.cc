#include "LobbyInfo.h"
#include "Proto.h"
#include "SqlStm.h"
#include "SqlManager.h"
#include "SqlStm.h"
#include <zdb/zdb.h>
#include <zdb/Exception.h>
#include <zdb/Connection.h>

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

LobbyInfo::LobbyInfo(const Json& in){
}

redbud::parser::json::Json
LobbyInfo::handle(){
    //TODO 
    out["response_type"]=static_cast<int>(T::FETCH_LOBBY_INFO_FAILED);
    out["reason"]="inner server error";
    return out;
}
