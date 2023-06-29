#pragma once

#include <iostream>
#include <string>

#include "PacketHandler.h"
#include "NetworkManager_Client.h"

class UserService
{
private:
    PacketHandler packetHandler;
    NetworkManager_Client& networkManager;

public:
    UserService(NetworkManager_Client& networkManager) : networkManager(networkManager) {}
public:
    void ShowMenu();

    void SignUp(std::string userid, std::string password);
    void Login(std::string userid, std::string password);
    void Logout(std::string userid);
};