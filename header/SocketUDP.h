#pragma once 
#include "./Socket.h" 
#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include <string>
#include <iostream>

#define PORT 5000 
#define MAXLINE 2000 

class SocketUDP : public Socket{
public:

char buffer[MAXLINE]; 
std::string message; 
SocketUDP();
virtual ~SocketUDP(){};
virtual void Send();
virtual void SendNSegmens(unsigned parNSeg){};
virtual void Receive();
virtual void Bind();



};
