#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>

//--Network-------------------------------------------------------------------
#include <WinSock2.h>
#include <Windows.h>
#include <mutex>

#define NET_PACKET_SIZE 512

#pragma comment (lib, "WS2_32.lib")

typedef unsigned char BYTE;

class NetworkManager_Client
{
private:
    WSAData                      NET_WSADATA = { 0, };
    SOCKET                       NET_CLIENTSOCKET = NULL;
    SOCKADDR_IN                  NET_SERVERADDR = { 0, };
    const char*                  NET_SERVER_IPV4 = "127.0.0.1";
    const int                    NET_SERVER_PORT = 5001;
    std::mutex                   NETWORK_MUTEX;

public:
    NetworkManager_Client();
    ~NetworkManager_Client();

public:
    void RunClient();
    void SendPacket(const char* buffer, int size);
};

