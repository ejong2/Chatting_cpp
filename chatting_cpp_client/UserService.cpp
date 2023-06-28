#include "UserService.h"

void UserService::ShowMenu()
{
    int option = 0;
    std::string userID, password;
    while (true)
    {
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter option: ";
        std::cin >> option;
        switch (option)
        {
            case 1:
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                std::cout << "Enter password: ";
                std::cin >> password;
                SignUp(userID, password);
                break;
            case 2:
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                std::cout << "Enter password: ";
                std::cin >> password;
                Login(userID, password);
                break;
            case 3:
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                Logout(userID);
                std::cout << "Quitting program.\n";
                return;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void UserService::SignUp(const std::string& userID, const std::string& password)
{
    Packet signUpPacket;
    packetHandler.MakeSignUpPacket(&signUpPacket, userID.c_str(), password.c_str());

    BYTE buffer[NET_PACKET_SIZE];
    packetHandler.Serialize(&signUpPacket, buffer);

    networkManager.SendPacket(buffer, signUpPacket.size);
}


void UserService::Login(const std::string& userID, const std::string& password)
{
    Packet loginPacket;
    packetHandler.MakeLoginPacket(&loginPacket, userID.c_str(), password.c_str());

    BYTE buffer[NET_PACKET_SIZE];
    packetHandler.Serialize(&loginPacket, buffer);

    networkManager.SendPacket(buffer, loginPacket.size);
}

void UserService::Logout(const std::string& userID)
{
    Packet logoutPacket;
    packetHandler.MakeLogoutPacket(&logoutPacket, userID.c_str());

    BYTE buffer[NET_PACKET_SIZE];
    packetHandler.Serialize(&logoutPacket, buffer);

    networkManager.SendPacket(buffer, logoutPacket.size);
}
