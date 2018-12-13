#include "CommunicationProcessor.h"



void CommunicationProcessor::handleClient(WiFiClient* wifiClient){
    CLOSE_SOCKET = false;

    while(!CLOSE_SOCKET){
        int bytesRead = wifiClient->readBytes(buffer,1024);
        dataManager.appendData(bufferReader.getDataReaded(buffer,bytesRead));
    
        if (checkIfEndLine(bytesRead)){
            handleDataRecv();
            dataManager.clearBuffer();
        }
    }
    Serial.println("CLIENT QUIT");

}

void CommunicationProcessor::handleDataRecv(){
    std::vector<std::string> lines = dataManager.getLines();
    for (std::string line : lines){
        std::string methodName (dataManager.getMethodIdent(line));
        std::string message (dataManager.getMessage(line));

        if (callMethod(this,methodName.c_str(),message.c_str())){
            CLOSE_SOCKET = true;
        }
    }
}


bool CommunicationProcessor::checkIfEndLine(int bytesRead){
    if (bytesRead >= Protocol::END_LINE_SIZE){
        const char* data = dataManager.getData();
        if ( Protocol::checkIfEndsWithEndLine(data,bufferReader.sizeOfConstChar(data))){
            return true;
        }
    }
    return false;
}
