#pragma once

#include <iostream>

#include "PacketEnums.h"
#include "PacketStructs.h"

typedef unsigned char BYTE;

class PacketHandler
{
public:
    PacketHandler() {}

    // ����ȭ �Լ�
    static void Serialize(Packet* packet, BYTE* buffer);
    // ������ȭ �Լ�
    static void Deserialize(BYTE* buffer, Packet* packet);

public:
    // ��Ŷ ���� �Լ�
    static void MakeSignUpPacket(Packet* packet, const char* id, const char* pw);
    static void MakeLoginPacket(Packet* packet, const char* id, const char* pw);
    static void MakeLogoutPacket(Packet* packet, const char* id);
    //static void MakeChatPacket(Packet* packet, const char* id, const char* chat);
};


