#ifndef _ENTRANCE_H
#define _ENTRANCE_H
#include <boost/any.hpp>
class Entrance{
public:
    Entrance(){}
    ~Entrance(){}
    void login();
    void logout();
    void registe();
    static void getUserInfo(Json j);
    static map<string,boost::any> result();
private:
    std::string username_;
    std::string pw_;
    map<string,boost::any>res;
};
#endif
