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
    bool result; // Request ó�� ����� ��Ÿ���ϴ�. true: ����, false: ����
};


struct LOGIN_REQUEST : public Packet
{
    char userID[50];
    char password[50];
};

struct LOGIN_RESPONSE : public ResponsePacket
{
    // �α��� ����� ������ �߰� �ʵ带 ���� �� �ֽ��ϴ�.
};

struct SIGNUP_REQUEST : public Packet
{
    char userID[50];
    char password[50];
};

struct SIGNUP_RESPONSE : public ResponsePacket
{
    // ȸ�� ���� ����� ������ �߰� �ʵ带 ���� �� �ֽ��ϴ�.
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