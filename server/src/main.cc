#include "GoServer.h"
#include "Sqlconn.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

int main(){
    LOG_INFO<<"pid = "<<getpid();
    EventLoop loop;
    InetAddress listenAddr(6000);
    GoServer server(&loop,listenAddr);
    server.start();
    Sqlconn sqlpool("mysql://localhost/go?user=Cloogo&password=1234");
    if(sqlpool.start()==false){
        LOG_ERROR<<"failed to create mysql connection pool";
        exit(1);
    }
    loop.loop();
}
