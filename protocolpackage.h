#ifndef PROTOCOLPACKAGE_H
#define PROTOCOLPACKAGE_H

#include <initializer_list>
#include <array>

template<unsigned char COMMAND, int LENGTH>
class ProtocolPackage
{
public:
    ProtocolPackage(const std::initializer_list<unsigned char> &list) {
        buffer[0] = 0xe1;
        buffer[1] = COMMAND;
        buffer[2] = LENGTH;
        int i = 3;
        for (auto data : list) {
            buffer[i++] = data;
        }
        buffer[i++] = 0; //crc1
        buffer[i++] = 0; //crc2
        buffer[i] = 0xfe;
    }
    unsigned char* GetBuffer() {
        return buffer.data();
    }

private:
    std::array<unsigned char, LENGTH> buffer;
};

#endif // PROTOCOLPACKAGE_H
