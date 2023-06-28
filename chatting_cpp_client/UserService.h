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
    UserService(NetworkManager_Client& manager) : networkManager(manager) {}

public:
    void ShowMenu();
    void SignUp(const std::string& userID, const std::string& password);
    void Login(const std::string& userID, const std::string& password);
    void Logout(const std::string& userID);
};