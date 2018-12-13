#include "CommunicationProcessor.h"



void CommunicationProcessor::handleClient(WiFiClient* wifiClient){
    CLOSE_SOCKET = false;
    this->activeWiFiClient = WiFiClient;

    while(!CLOSE_SOCKET && wifiClient->connected()){
        
        int available;
        if ((available = wifiClient->available() ) > 0){
            int bytesRead = wifiClient->readBytes(buffer,(available <= BUFFER_SIZE) ? available : BUFFER_SIZE);
            dataManager.appendData(bufferReader.getDataReaded(buffer,bytesRead));
            
            if (checkIfEndLine(bytesRead)){
                handleDataRecv();
                dataManager.clearBuffer();
            }
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

void CommunicationProcessor::send(const char* classIdent,const char* methodIdent,const char* message){
    const char* modifiedString = Protocol::concatDataString(classIdent,methodIdent,message);
    this->activeWiFiClient->write(modifiedString);
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
