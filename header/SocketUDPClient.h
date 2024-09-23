#pragma once
#include "./SocketUDP.h"

class SocketUDPClient : public SocketUDP{

public:

SocketUDPClient();
~SocketUDPClient(){close(sockfd);};//A classe concreta não precisa de destrutor virtual.
virtual void Send();
virtual void SendNSegmens(unsigned parNSeg);
virtual void Receive();
virtual void Bind();

int sockfd, n; 
struct sockaddr_in servaddr; 

};
