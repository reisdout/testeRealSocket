#pragma once
#include "./SocketUDP.h"


class SocketUDPServer : public SocketUDP{
public:

int listenfd, len; 
struct sockaddr_in servaddr, cliaddr; 

SocketUDPServer();
~SocketUDPServer(){};
virtual void Send();
virtual void Receive();
virtual void Bind();
};