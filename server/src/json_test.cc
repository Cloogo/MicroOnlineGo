#include <iostream>
#include <redbud/parser/json_parser.h>
#include <redbud/parser/json.h>

using namespace redbud::parser::json;
using namespace std;

int
main(){
    Json j=Json::parse("{\"id\":1,\"pw\":\"Hello 世界!\"}");
    j.print(Json::PrintType::Pretty);
    Json j2;
    j2["id"]=1;
    j2["pw"]="Hello 世界!";
    j2.print(Json::PrintType::Pretty);
    int id=j2["id"].as_number();
    cout<<id<<endl;
}
