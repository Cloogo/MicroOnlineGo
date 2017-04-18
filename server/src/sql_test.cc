#include <iostream>
#include <mysql/mysql.h>
#include <map>
using namespace std;
static int count=0;
map<int,MYSQL*>test;

void
add(){
    MYSQL* sqlconn=mysql_init(NULL);
    if(sqlconn==NULL){
        cout<<"Error"<<endl;
    }
    if(mysql_real_connect(sqlconn,"localhost","Cloogo","1234","go",0,NULL,0)==NULL){
        cout<<"Error"<<endl;
    }
    test[count++]=sqlconn;
}

int
main(){
    for(int i=0;i<10;i++){
        add();
    }
    for(int i=0;i<9;i++){
        if(test[i]==test[i+1]){
            cout<<"Failed"<<endl;
        }
    }
    for(int i=0;i<10;i++){
        MYSQL* sql=test[i];
        mysql_close(sql);
    }
}
