#include "PairManager.h"

using namespace std;
using namespace muduo;
using namespace muduo::net;

pthread_once_t PairManager::ponce=PTHREAD_ONCE_INIT;
PairManager* PairManager::instance=NULL;
pthread_mutex_t pm_mutex=PTHREAD_MUTEX_INITIALIZER;

void
PairManager::setCb(const msgCb& sendBack_){
    sendBack=sendBack_;
}

bool
PairManager::find(const int id){
    Iter i=pairsList.find(id);
    if(i!=pairsList.end()){
        return true;
    }
    return false;
}

ORDER
PairManager::add(const TcpConnectionPtr& conn,const int id){
    ORDER order=ORDER::LEFT;
    pthread_mutex_lock(&pm_mutex);
    if(find(id)){
        ConnPair& connPair=pairsList[id];
        if(connPair.first==nullptr){
            connPair.first=conn;
        }else{
            connPair.second=conn;
            order=ORDER::RIGHT;
        }
    }else{
        ConnPair connPair;
        connPair.first=conn;
        pairsList[id]=connPair;
    }
    pthread_mutex_unlock(&pm_mutex);
    return order;
}

void
PairManager::remove(const TcpConnectionPtr& conn,const int id){
    pthread_mutex_lock(&pm_mutex);
    if(find(id)){
        ConnPair& connPair=pairsList[id];
        if(connPair.first==conn){
            connPair.first=nullptr;
        }else if(connPair.second==conn){
            connPair.second=nullptr;
        }
        if(connPair.first==nullptr&&connPair.second==nullptr){
            pairsList.erase(id);
        }
    }
    pthread_mutex_unlock(&pm_mutex);
}

int
PairManager::match(){
    pthread_mutex_lock(&pm_mutex);
    for(Iter i=pairsList.begin();i!=pairsList.end();++i){
        if(i->second.first==nullptr||i->second.second==nullptr){
            pthread_mutex_unlock(&pm_mutex);
            return i->first;
        }
    }
    pthread_mutex_unlock(&pm_mutex);
    return -1;
}

ORDER
PairManager::pos(const TcpConnectionPtr& self,const int id){
    ConnPair& connPair=pairsList[id];
    if(connPair.first==self){
        return ORDER::LEFT;
    }else if(connPair.second==self){
        return ORDER::RIGHT;
    }
}

void
PairManager::singlecast(const TcpConnectionPtr& self,const int id,std::string msg){
    pthread_mutex_lock(&pm_mutex);
    if(find(id)){
        ConnPair connPair=pairsList[id];
        if(connPair.first!=self){
            sendBack(connPair.first,msg);
        }else{
            sendBack(connPair.second,msg);
        }
    }
    pthread_mutex_unlock(&pm_mutex);
}
