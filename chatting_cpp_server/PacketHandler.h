#pragma once

#include <iostream>
#include "PacketStructs.h"

typedef unsigned char BYTE;

class PacketHandler
{
public:
    PacketHandler() {}

public:
    //// 만든 패킷 구조를 버퍼에 직렬화 하는 메서드
    //static void Serialize(BYTE* buffer, const Packet& packet);

    //// 버퍼에 직렬화된 패킷 구조를 역직렬화 하는 메서드
    //void Deserialize(BYTE* buffer, Packet& packet, int packetSize);

public:
    // TODO : 회원가입 응답 패킷을 만드는 메서드

    // TODO : 로그인 응답 패킷을 만드는 메서드

    // TODO : 로그아웃 응답 패킷을 만드는 메서드

};