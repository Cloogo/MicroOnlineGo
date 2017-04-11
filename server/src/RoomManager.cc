#include "RoomManager.h"
#include <iostream>

using namespace std;
using namespace muduo;
using namespace muduo::net;

RoomManager::RoomManager(){
}

RoomManager::~RoomManager(){
}

bool
RoomManager::find(const int roomId){
    Iter i=rooms_.find(roomId);
    if(i!=rooms_.end()){
        return true;
    }
    return false;
}

void
RoomManager::add(const TcpConnectionPtr& conn,const int roomId){
    if(find(roomId)){
        ConnsList& room=rooms_[roomId];
        room.insert(conn);
    }else{
        ConnsList room;
        room.insert(conn);
        rooms_[roomId]=room;
    }
}

void
RoomManager::remove(const TcpConnectionPtr& conn,const int roomId){
    if(find(roomId)){
        ConnsList& room=rooms_[roomId];
        room.erase(conn);
    }else{
    }
}

void
RoomManager::broadcast(const int roomId,std::string msg){
    if(find(roomId)){
        ConnsList room=rooms_[roomId];
        for(set<TcpConnectionPtr>::iterator it=room.begin();it!=room.end();it++){
            (*it)->send(msg);
        }
    }
}
