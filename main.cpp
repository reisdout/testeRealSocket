#include <stdio.h>
#include "./header/SocketUDP.h"

int main(int, char**){
    printf("Hello, from udpSocket!\n");

    Socket* ptSocket;
    ptSocket = new SocketUDP();
    ptSocket->Send();
    ptSocket->Receive();
    ptSocket->Bind();

    delete ptSocket;
}
