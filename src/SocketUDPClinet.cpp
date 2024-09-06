#include "./SocketUDPClient.h"



SocketUDPClient::SocketUDPClient()
{
    this->message= "Hello  my Server";
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET; 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

}


void SocketUDPClient::Send()
{
    std::cout << "Enviando...\n";
}

void SocketUDPClient::Receive()
{
    std::cout << "Recebendo\n";
}

void SocketUDPClient::Bind()
{
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
    { 
        printf("\n Error : Connect Failed \n"); 
        exit(0); 
    } 
}
