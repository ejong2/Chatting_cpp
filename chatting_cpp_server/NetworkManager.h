#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>

//--Network-------------------------------------------------------------------
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <mutex>
#include <string>

#pragma comment (lib, "WS2_32.lib")

class NetworkManager
{
private:
    WSAData                      NET_WSADATA = { 0, };
    SOCKET                       NET_SERVERSOCKET = NULL;
    SOCKADDR_IN                  NET_SERVERADDR = { 0, };
    const char*                  NET_SERVER_IPV4 = "127.0.0.1";
    const int                    NET_SERVER_PORT = 5001;
    const int                    NET_PACKET_SIZE = 512;
    std::mutex                   NETWORK_MUTEX;

public:
    NetworkManager();
    ~NetworkManager();

public:
    void RunServer();
};