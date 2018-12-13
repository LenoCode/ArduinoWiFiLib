#include "BufferReader.h"
#include <ESP8266WiFi.h>
#include "DataManager.h"
#include "MethodsHolder.h"
#include "Flags.h"

class CommunicationProcessor : public MethodsHolder,public Flags{
private:
    unsigned char buffer[1024];
    DataManager dataManager;
    BufferReader bufferReader;
    bool checkIfEndLine(int bytesRead);
    void handleDataRecv();
protected:
    void handleClient(WiFiClient* wifiClient);
public:
};
