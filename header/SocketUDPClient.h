#include "./SocketUDP.h"

class SocketUDPClient : public SocketUDP{

public:

SocketUDPClient();
~SocketUDPClient(){};//A classe concreta não precisa de destrutor virtual.
virtual void Send();
virtual void Receive();
virtual void Bind();

int sockfd, n; 
struct sockaddr_in servaddr; 

};
