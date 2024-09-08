#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
using namespace std;
int main(){
char msg[1234]="what";
    int create_client= socket(AF_INET,SOCK_STREAM,0);
    //get ip and address
    struct sockaddr_in server_addr;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(5050);
    server_addr.sin_addr.s_addr= INADDR_ANY;
    //bind()
    bind(create_client,(sockaddr *)&server_addr,sizeof(server_addr));
    //connect
    connect(create_client,(sockaddr*)&server_addr, sizeof(server_addr));
    send(create_client,&msg,sizeof(msg),0);
    close(create_client);
