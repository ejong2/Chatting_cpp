#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h> 
#include <Windows.h>
#include <process.h>

#pragma comment (lib, "WS2_32.lib")

WSAData wsaData = { 0, };
SOCKET clientSocket = NULL;
SOCKADDR_IN serverAddr = { 0, };
const char* SERVER_IPV4 = "127.0.0.1";
const int SERVER_PORT = 5001;
const int PACKET_SIZE = 512;

int main()
{
    std::cout << "Chatting_cpp Client v20230627" << std::endl;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "[ERR] WSAStartup Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-1);
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cout << "[ERR] ClientSocket Creation Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-2);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr(SERVER_IPV4);
    serverAddr.sin_port = htons(SERVER_PORT);
    if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) != 0)
    {
        std::cout << "[ERR] ServerSocket Connect Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-3);
    }

    std::cout << "[SYS] Connected to Server!" << std::endl;

    while (true)
    {
        char packet[PACKET_SIZE] = { 0, };
        int recvSize = recv(clientSocket, packet, PACKET_SIZE, 0);
        if (recvSize > 0)
        {
            std::cout << "[RECV] " << packet << std::endl;
        }
        else if (recvSize == 0)
        {
            std::cout << "[SYS] Disconnected from Server!" << std::endl;
            break;
        }
        else
        {
            std::cout << "[ERR] recv Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
            break;
        }
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
