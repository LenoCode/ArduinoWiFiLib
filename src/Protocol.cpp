#include "Protocol.h"

const char* Protocol::END_LINE ="</END LINE>";
const int Protocol::END_LINE_SIZE = 11;

const char* Protocol::SOCKET_CLOSED = "</SOCKET_CLOSED>Socket closed>";
const int Protocol::SOCKET_CLOSED_SIZE = 30;




bool Protocol::checkIfEndsWithEndLine(const char* data,int dataSize){
    return check(data,dataSize,END_LINE,END_LINE_SIZE);
}

bool Protocol::check(const char* dataToCheck,int dataSize, const char* comparingTo, int comparingToSize){
    for ( int i = comparingToSize -1, j = dataSize - 1 ; i > -1 ; --i,--j  ){
        if (comparingTo[i] != dataToCheck[j]){
            return false;
        }
    }
    return true;
}

