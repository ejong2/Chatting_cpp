#include "NetworkManager_Client.h"

NetworkManager_Client::NetworkManager_Client()
{
    if (WSAStartup(MAKEWORD(2, 2), &NET_WSADATA) != 0)
    {
        std::cout << "[ERR] WSAStartup Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-1);
    }

    NET_CLIENTSOCKET = socket(AF_INET, SOCK_STREAM, 0);
    if (NET_CLIENTSOCKET == INVALID_SOCKET)
    {
        std::cout << "[ERR] ClientSocket Creation Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-2);
    }

    NET_SERVERADDR.sin_family = AF_INET;
    NET_SERVERADDR.sin_addr.S_un.S_addr = inet_addr(NET_SERVER_IPV4);
    NET_SERVERADDR.sin_port = htons(NET_SERVER_PORT);
    if (connect(NET_CLIENTSOCKET, (SOCKADDR*)&NET_SERVERADDR, sizeof(NET_SERVERADDR)) != 0)
    {
        std::cout << "[ERR] ServerSocket Connect Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-3);
    }

    std::cout << "[SYS] Connected to Server!" << std::endl;
}

NetworkManager_Client::~NetworkManager_Client()
{
    closesocket(NET_CLIENTSOCKET);
    WSACleanup();
}

void NetworkManager_Client::RunClient()
{
    while (true) // G_PROGRAMRUNNING을 참조할 수 없으므로 일단 무한루프로 대체합니다.
    {
        char packet[NET_PACKET_SIZE] = { 0, };
        int recvSize = recv(NET_CLIENTSOCKET, packet, NET_PACKET_SIZE, 0);
        if (recvSize == SOCKET_ERROR)
        {
            std::cout << "[ERR] Packet Receive Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
            exit(-4);
        }
        else if (recvSize == 0)
        {
            std::cout << "[SYS] Server Disconnected!" << std::endl;
            break;
        }
        else
        {
            std::cout << "[SYS] Packet Received! Size : " << recvSize << std::endl;
            std::cout << "[SYS] Packet Data : " << packet << std::endl;
        }
    }
}
