#include <WiFiLib/wifi/wifi_models/controllers_models/wifi_configurator/WiFiConfigurator.h>
#include <WiFiLib/wifi/wifi_models/controllers_models/wifi_status/WiFiStatus.h>

class Connector : public WiFiConfigurator,public WiFiStatus {
private:
    void setSsidAndPassword() override;
public:
    Connector() = default;;
    Connector(const char* ssid,const char* password);
    uint8_t getNumberOfConnections();
};