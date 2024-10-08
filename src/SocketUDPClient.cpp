#include "./SocketUDPClient.h"



SocketUDPClient::SocketUDPClient()
{
    this->message= "Hello  my Server";
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_addr.s_addr = inet_addr("192.168.0.106"); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET; 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

}


void SocketUDPClient::Send()
{
    sendto(sockfd, message.c_str(), MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr)); 
}


void SocketUDPClient::SendNSegmens(unsigned parNSeg)
{
    unsigned msgSize = 1.2 * SEGMENT_SIZE;
    
    for (unsigned i=0; i<parNSeg;i++)
    {
        this->message.clear();
        printf("Gerando %d Mensagem......\n", msgSize);
        for (unsigned j=0; j< msgSize; j++)
            message = message+'a';
    
        printf("Mandando:\n");
        printf("%s", message.c_str());
        printf("\n");
        sendto(sockfd, message.c_str(), message.size(), 0, (struct sockaddr*)NULL, sizeof(servaddr));
    }


}

void SocketUDPClient::Receive()
{
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); //Fica esperando
    puts(buffer); 
}

void SocketUDPClient::Bind()
{
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
    { 
        printf("\n Error : Connect Failed \n"); 
        exit(0); 
    } 
}
