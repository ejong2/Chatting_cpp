#pragma once

#include <iostream>

#include "PacketEnums.h"
#include "PacketStructs.h"

using namespace std;

class PacketProcessor
{
public:
    void processPacket(Packet* packet);

private:
    void processSignUpPacket(Packet* packet);
    void processLoginPacket(Packet* packet);
    void processLogoutPacket(Packet* packet);
    //void processChatPacket(Packet* packet);
};

