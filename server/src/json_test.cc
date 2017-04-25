#include <iostream>
#include <redbud/parser/json_parser.h>
#include <redbud/parser/json.h>


using namespace redbud::parser::json;
using namespace std;

int
main(){
    Json j3;
    j3["project"] = "redbud test";
    j3["file"] = 10;
    j3["finished"] = false;
    j3["list"] = Json::Array{ Json::Object{{"Name","a"},{"age",20}},{"json.cc" }};
    j3["author"] = Json::Object{ {"Name","Alinshans"},{"age",18} };
    j3["hhhh"]=111111111;
    Json j4;
    Json j5;
    j5["play_num"]=10;
    string name="Unit";
    j4.push_back(Json::Object{{"Test",name},{"passed",100}});
    j4.push_back(Json::Object{{"Test","Mock"},{"passed",10}});
    if(j4.size()!=0){
        j5["players"]=j4;
    }
    cout<<j5.dumps()<<endl;
    string msg="Hello world!";
    Json j6=Json::parse("{\"name\":\"Test\",\"msg\":\"Hello world\"}");
    cout<<j6.dumps()<<endl;
}
