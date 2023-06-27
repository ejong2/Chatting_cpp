#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
    if (WSAStartup(MAKEWORD(2, 2), &NET_WSADATA) != 0)
    {
        std::cout << "[ERR] WSAStartup Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-1);
    }

    NET_SERVERSOCKET = socket(AF_INET, SOCK_STREAM, 0);
    if (NET_SERVERSOCKET == INVALID_SOCKET)
    {
        std::cout << "[ERR] ServerSocket Creation Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-2);
    }

    NET_SERVERADDR.sin_family = AF_INET;
    NET_SERVERADDR.sin_addr.S_un.S_addr = inet_addr(NET_SERVER_IPV4);
    NET_SERVERADDR.sin_port = htons(NET_SERVER_PORT);
    if (::bind(NET_SERVERSOCKET, (SOCKADDR*)&NET_SERVERADDR, sizeof(NET_SERVERADDR)) != 0)
    {
        std::cout << "[ERR] ServerSocket Bind Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-3); 
    }

    if (listen(NET_SERVERSOCKET, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "[ERR] ServerSocket Listen Error Occurred. ErrorCode : " << WSAGetLastError() << std::endl;
        exit(-4);
    }

    std::cout << "[SYS] ServerSocket [" << NET_SERVERSOCKET << "] Listen Started!" << std::endl;
}

NetworkManager::~NetworkManager()
{
    std::cout << "[SYS] ServerSocket [" << NET_SERVERSOCKET << "] Listen Finished!" << std::endl;

    NETWORK_MUTEX.lock();
    for (auto& pair : THREAD_POOL)
    {
        if (pair.second.joinable())
        {
            pair.second.join();
        }
    }
    NETWORK_MUTEX.unlock();

    closesocket(NET_SERVERSOCKET);
    WSACleanup();
}

void NetworkManager::RunServer()
{
    while (true) 
    {
        SOCKADDR_IN ClientAddr = { 0, };
        int szClientAddr = sizeof(ClientAddr);
        SOCKET ClientSocket = accept(NET_SERVERSOCKET, (SOCKADDR*)&ClientAddr, &szClientAddr);
        if (ClientSocket == INVALID_SOCKET)
        {
            closesocket(ClientSocket);
            continue;
        }
        std::cout << "[SYS] ClientSocket [" << ClientSocket << "] Connected!" << std::endl;

        // Spawn a new thread to handle the client socket
        std::thread t(&NetworkManager::ProcessClientSocket, this, ClientSocket);
        NETWORK_MUTEX.lock();
        THREAD_POOL[ClientSocket] = std::move(t);
        NETWORK_MUTEX.unlock();
    }
}

void NetworkManager::ProcessClientSocket(SOCKET ClientSocket)
{
    char RecvBuffer[NET_PACKET_SIZE] = { 0, };
    int RecvBytes = 0;

    while (true) 
    {
        memset(RecvBuffer, 0, sizeof(RecvBuffer));
        RecvBytes = recv(ClientSocket, RecvBuffer, sizeof(RecvBuffer), 0);
        if (RecvBytes <= 0) { break; }
        //Retval = ProcessPacket(ClientSocket, &RecvBuffer[0]);
        // 여기에서 패킷을 처리.
    }

    std::cout << "[SYS] ClientSocket [" << ClientSocket << "] Disconnected!" << std::endl;
    closesocket(ClientSocket);
}
