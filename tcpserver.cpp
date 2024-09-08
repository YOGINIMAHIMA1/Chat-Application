#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>//
#include <unistd.h>
#include <cstring>
using namespace std;
int main(){
    //create socket
    int create_socket= socket(AF_INET,SOCK_STREAM,0);
    //get ip and port
    struct sockaddr_in serveraddr;
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr= INADDR_ANY;
    serveraddr.sin_port= htons(5050);

    //bind the ip and port to scoket
    bind(create_socket,(struct sockaddr *)&serveraddr, sizeof(serveraddr));
    //listen
    listen(create_socket,SOMAXCONN);
    //Accept
int new_socket=accept(create_socket,NULL,NULL );
char buffer[1234];
    //recv
    recv(new_socket,&buffer,sizeof(buffer),0);
    cout<<buffer<<endl;
    close(new_socket);

    close(create_socket);
}
