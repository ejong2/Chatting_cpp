#pragma once

#include <cstring>
#include "PacketEnums.h"

typedef unsigned char BYTE;

struct Packet
{
    int size;
    PacketID id;
    BYTE data[255];
};

struct ResponsePacket : public Packet
{
    bool result; // Request 처리 결과를 나타냅니다. true: 성공, false: 실패
};


struct LOGIN_REQUEST : public Packet
{
    char userID[50];
    char password[50];
};

struct LOGIN_RESPONSE : public ResponsePacket
{
    // 로그인 결과를 보여줄 추가 필드를 넣을 수 있습니다.
};

struct SIGNUP_REQUEST : public Packet
{
    char userID[50];
    char password[50];
};

struct SIGNUP_RESPONSE : public ResponsePacket
{
    // 회원 가입 결과를 보여줄 추가 필드를 넣을 수 있습니다.
};

struct LOGOUT : public Packet
{
    char userID[50];
};

struct CHAT_MESSAGE : public Packet
{
    char userID[50];
    char message[255];
};

struct CHAT_BROADCAST : public Packet
{
    char userID[50];
    char message[255];
};

struct ROOM_CREATE : public Packet
{
    char userID[50];
    char roomName[50];
};

struct ROOM_JOIN : public Packet
{
    char userID[50];
    char roomName[50];
};

struct ROOM_LEAVE : public Packet
{
    char userID[50];
    char roomName[50];
};

struct ROOM_DELETE : public Packet
{
    char userID[50];
    char roomName[50];
};

struct ROOM_USER_LIST : public Packet
{
    char roomName[50];
};