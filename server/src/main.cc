#include "GoServer.h"
#include "SqlManager.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <pthread.h>

using namespace muduo;
using namespace muduo::net;

pthread_once_t SqlManager::ponce=PTHREAD_ONCE_INIT;
SqlManager* SqlManager::instance=NULL;
std::string SqlManager::url="mysql://localhost/go?user=Cloogo&password=1234";
int SqlManager::maxConnsNum=1024;

int main(){
    LOG_INFO<<"pid = "<<getpid();
    EventLoop loop;
    InetAddress listenAddr(6000);
    GoServer server(&loop,listenAddr);
    server.start();
    if(SqlManager::getInstance().start()==false){
        LOG_ERROR<<"failed to create mysql connection pool";
        exit(1);
    }
    loop.loop();
}
