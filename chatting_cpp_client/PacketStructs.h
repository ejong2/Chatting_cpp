#pragma once

#define WINDOW_IGNORE_PACKING_MISMATCH

#include "PacketEnums.h"

#pragma pack(push,1)

struct PACKET_HEADER
{
    int PacketID;
    int PacketSize;
};

struct PACKET_REQ_SIGNUP
{
    PACKET_HEADER PkHeader;
    char UserName[32];
    char Password[32];
};

struct PACKET_RES_SIGNUP
{
    PACKET_HEADER PkHeader;
    int Result;
};

struct PACKET_REQ_LOGIN
{
    PACKET_HEADER PkHeader;
    char UserName[32];
    char Password[32];
};

struct PACKET_RES_LOGIN
{
    PACKET_HEADER PkHeader;
    int Result;
};

struct PACKET_REQ_LOGOUT
{
    PACKET_HEADER PkHeader;
    char UserName[32];
};

struct PACKET_RES_LOGOUT
{
    PACKET_HEADER PkHeader;
    int Result;
};

#pragma pack(pop)