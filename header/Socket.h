#pragma once

#define SEGMENT_SIZE 1500

class Socket {

protected:
    unsigned segmentsReceived=0;
public:
    Socket(){};
    virtual ~Socket(){}; //precisa ser virtual para ser chamado quando ser deleta 
                        //a classe base ver https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    // pure virtual functions
    virtual void Send() = 0;
    virtual void SendNSegmens(unsigned parNSeg)=0;
    virtual void Receive()=0;
    virtual void Bind()=0;
    
};