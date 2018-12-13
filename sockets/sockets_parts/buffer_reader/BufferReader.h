#include <WiFiLib/main_lib/mainLib.h>

class BufferReader{
private:
protected:
public:
    const char* getDataReaded(unsigned char buffer[],int bytesRead);
    int sizeOfConstChar(const char* data);
};