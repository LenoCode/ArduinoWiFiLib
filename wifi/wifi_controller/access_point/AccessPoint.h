//
// Created by Filip Ćaćić on 13/11/2018.
//

#ifndef WIFILIB_ACCESSPOINT_H
#define WIFILIB_ACCESSPOINT_H


#include <WiFiLib/wifi/wifi_models/controllers_models/wifi_configurator/WiFiConfigurator.h>
#include <WiFiLib/wifi/wifi_models/controllers_models/wifi_status/WiFiStatus.h>

class AccessPoint : public WiFiConfigurator,public WiFiStatus {
private:
    void setSsidAndPassword() override;
public:
    AccessPoint() = default;;
    AccessPoint(const char* ssid,const char* password);
    uint8_t getNumberOfConnections();
};


#endif //WIFILIB_ACCESSPOINT_H
