#include "../header/SocketUDPServer.h"


SocketUDPServer::SocketUDPServer()
{
    this->message = "Hello my Client"; 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // Create a UDP Socket 
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);         
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET;  
}

void SocketUDPServer:: Send()
{
sendto(listenfd, this->message.c_str(), MAXLINE, 0, 
          (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 

}

void SocketUDPServer::Receive()
{
    len = sizeof(cliaddr); 
    int n = recvfrom(listenfd, buffer, sizeof(buffer), 
            0, (struct sockaddr*)&cliaddr,(socklen_t *)&len); //receive message from server 
    buffer[n] = '\0'; 
    puts(buffer);
    this->Send();
}

void SocketUDPServer::Bind()
{
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
}