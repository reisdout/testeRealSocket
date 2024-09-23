#include <stdio.h>
#include "./header/SocketUDPClient.h"
#include "./header/SocketUDPServer.h"

int main(int argc, char**argv){
    printf("Hello, from udpSocket!\n");
    Socket* ptSocket=0;
    //bool server = true;
    //bool debug = true;
    std::cout << argv[1]<<"\n";
    if(std::string(argv[1]) == "client" )
    {
        if(argc < 3)
        {
            printf("Packets missing\n");
        }
        else
        {
            ptSocket = new SocketUDPClient();
            ptSocket->Bind();
            int n = 0;
            while(n < std::stoi(std::string(argv[2])))
            {
                ptSocket->SendNSegmens(1);
                n++;
            }
            ptSocket->Receive();
        }

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
    else
        printf("Wrong parameters\n"); 

        
    
    if(ptSocket)
        delete ptSocket;

}
