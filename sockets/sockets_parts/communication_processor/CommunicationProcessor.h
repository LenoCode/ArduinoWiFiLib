#include "WiFiLib/sockets/sockets_parts/buffer_reader/BufferReader.h"
#include <ESP8266WiFi.h>
#include "WiFiLib/sockets/sockets_parts/data_manager/DataManager.h"
#include "WiFiLib/sockets/sockets_parts/methods_holder/MethodsHolder.h"
#include "WiFiLib/sockets/sockets_parts/flags/Flags.h"

class CommunicationProcessor : public MethodsHolder,public Flags{
private:
    int BUFFER_SIZE;
    WiFiClient* activeWiFiClient;
    unsigned char buffer[256];
    DataManager dataManager;
    BufferReader bufferReader;
    bool checkIfEndLine(int bytesRead);
    void handleDataRecv();
    void closeSocket();
protected:
    void handleClient(WiFiClient* wifiClient);
public:
    CommunicationProcessor():BUFFER_SIZE(256){};
    void send(const char* classIdent,const char* methodIdent,const char* message);
};
