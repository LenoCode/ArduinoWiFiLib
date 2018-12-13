//
// Created by Filip Ćaćić on 09/11/2018.
//

#ifndef WIFILIB_WIFICONTROLLER_H
#define WIFILIB_WIFICONTROLLER_H
#include "../../../../../../../../../../.platformio/packages/framework-arduinoespressif8266/libraries/ESP8266WiFi/src/ESP8266WiFi.h"
#include "../../main_lib/mainLib.h"


template<typename ControllerPolicy>
class WiFiController : public ControllerPolicy{
private:
public:
    WiFiController() = default;;
};



#endif //WIFILIB_WIFICONTROLLER_H
