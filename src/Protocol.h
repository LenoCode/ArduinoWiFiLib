#include"WiFiLib/main_lib/mainLib.h"

class Protocol{
public:
    static const char* END_LINE;
    static const int END_LINE_SIZE;

    static const char* SOCKET_CLOSED;
    static const int SOCKET_CLOSED_SIZE;

    static const char* DATA_STRING;

    static bool checkIfEndsWithEndLine(const char* data,int dataSize);

    static bool check(const char* dataToCheck,int dataSize, const char* comparingTo, int comparingToSize);

    static const char* concatDataString(const char* classIdent,const char* methodIdent,const char* message);
private:

};