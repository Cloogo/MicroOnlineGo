#include "RoomManager.h"
#include <muduo/base/Logging.h>
using namespace std;
using namespace muduo;
using namespace muduo::net;

pthread_once_t RoomManager::ponce=PTHREAD_ONCE_INIT;
RoomManager* RoomManager::instance=NULL;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void
RoomManager::setCb(const msgCb& sendBack_){
    sendBack=sendBack_;
}

bool
RoomManager::find(const int roomId){
    Iter i=rooms.find(roomId);
    if(i!=rooms.end()){
        return true;
    }
    return false;
}

void
RoomManager::add(const TcpConnectionPtr& conn,const int roomId){
    pthread_mutex_lock(&mutex);
    if(find(roomId)){
        ConnsList& room=rooms[roomId];
        room.insert(conn);
    }else{
        ConnsList room;
        room.insert(conn);
        rooms[roomId]=room;
    }
    pthread_mutex_unlock(&mutex);
}

void
RoomManager::remove(const TcpConnectionPtr& conn,const int roomId){
    pthread_mutex_lock(&mutex);
    if(find(roomId)){
        ConnsList& room=rooms[roomId];
        room.erase(conn);
        LOG_INFO<<"REMOVE"<<conn->peerAddress().toIpPort()<<"->"
            <<conn->localAddress().toIpPort();
    }else{
    }
    pthread_mutex_unlock(&mutex);
}

void
RoomManager::broadcast(const int roomId,std::string msg){
    pthread_mutex_lock(&mutex);
    if(find(roomId)){
        ConnsList room=rooms[roomId];
        for(set<TcpConnectionPtr>::iterator it=room.begin();it!=room.end();it++){
            sendBack(*it,msg);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void
RoomManager::broadcast2(const TcpConnectionPtr& conn,const int roomId,std::string msg){
    pthread_mutex_lock(&mutex);
    if(find(roomId)){
        ConnsList room=rooms[roomId];
        for(set<TcpConnectionPtr>::iterator it=room.begin();it!=room.end();it++){
            if(*it==conn){
                continue;
            }
            sendBack(*it,msg);
        }
    }
    pthread_mutex_unlock(&mutex);
}
