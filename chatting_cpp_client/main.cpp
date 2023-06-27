#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h> 
#include <Windows.h>
#include <process.h>

#include "NetworkManager_Client.h"

int main()
{
    std::cout << "Chatting_cpp Client v20230627" << std::endl;

    NetworkManager_Client client;
    client.RunClient();

    return 0;
}
