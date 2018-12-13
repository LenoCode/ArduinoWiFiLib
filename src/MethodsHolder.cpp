//
// Created by Filip Ćaćić on 16/11/2018.
//

#include "MethodsHolder.h"
#include "../../../../../../../../../../../.platformio/packages/toolchain-xtensa/xtensa-lx106-elf/include/c++/4.8.2/utility"

void MethodsHolder::addNotificationMethod(const char *methodName, bool (*func)(CommunicationProcessor*,const char*)) {
    methods.insert(std::pair<const char*,bool(*)(CommunicationProcessor*,const char*)>(methodName,func));
}

bool MethodsHolder::callMethod(CommunicationProcessor* communicationProcessor,const char *methodName,const char* notification){
    bool result = methods.at(methodName)(communicationProcessor,notification);
    return result;
}

