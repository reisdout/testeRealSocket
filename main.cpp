#include <stdio.h>
#include "./header/SocketUDPClient.h"
#include "./header/SocketUDPServer.h"

int main(int argc, char**argv){
    printf("Hello, from udpSocket!\n");
    Socket* ptSocket=0;
    //bool server = true;
    //bool debug = true;
    std::cout << argv[1]<<"\n";
    if(argc == 2)
    {

        if(std::string(argv[1]) == "client" )
        {
            
            ptSocket = new SocketUDPClient();
            ptSocket->Bind();
            int n = 0;
            while(n < 10)
            {
                ptSocket->Send();
                n++;
            }
            ptSocket->Receive();

        }
        else if (std::string(argv[1]) == "server" )
        {
            ptSocket = new SocketUDPServer();
            std::cout << "Servidor instanciado\n";
            ptSocket->Bind();
            std::cout <<"Press any key to stop\n";
            while(true)
                ptSocket->Receive();

 
        }

        
    }
    else
        std::cout << "Wrong Command format (udpSocket -client or -server)\n";
    
    if(ptSocket)
        delete ptSocket;

}
