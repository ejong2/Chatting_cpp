#pragma once

#include <iostream>

#include "PacketEnums.h"
#include "PacketStructs.h"

typedef unsigned char BYTE;

class PacketHandler
{
public:
    PacketHandler() {}

    // 직렬화 함수
    static void Serialize(Packet* packet, BYTE* buffer);
    // 역직렬화 함수
    static void Deserialize(BYTE* buffer, Packet* packet);

public:
    // 패킷 생성 함수
    static void MakeSignUpPacket(Packet* packet, const char* id, const char* pw);
    static void MakeLoginPacket(Packet* packet, const char* id, const char* pw);
    static void MakeLogoutPacket(Packet* packet, const char* id);
    //static void MakeChatPacket(Packet* packet, const char* id, const char* chat);
};


