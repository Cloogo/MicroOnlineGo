#include "Account.h"
#include "Proto.h"
#include "SqlStm.h"

#define T RESPONSE_TYPE

using namespace redbud::parser::json;

Account::Account(const Json& in){
    account=in["account"].as_string();
}

Json
Account::check(){
    std::string stm="select * from users where account=\""+account+"\"";
    if(SqlStm::isExisted(stm)){
        out["response_type"]=static_cast<int>(T::ACCOUNT_CHECK_FAILED);
        out["reason"]="account already exists";
    }else{
        out["response_type"]=static_cast<int>(T::ACCOUNT_CHECK_SUCCESS);
        out["reason"]="account not exists";
    }
    return out;
}

Json
Account::handle(){
    return check();
}
