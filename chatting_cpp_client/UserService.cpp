#include "UserService.h"


void UserService::ShowMenu()
{
    int option = 0;

    //userID, password를 char[] 형태로 선언
    char userID[32] = { 0, };
    char password[32] = { 0, };

    

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

void UserService::SignUp(std::string id, std::string pas)
{
    PACKET_REQ_SIGNUP ReqPk = { 0, };
    ReqPk.PkHeader.PacketID = (int)PacketID::C2S_SIGNUP_REQUEST;
    ReqPk.PkHeader.PacketSize = sizeof(PACKET_REQ_SIGNUP);
    strncpy_s(ReqPk.Password, pas.c_str(), sizeof(ReqPk.Password) - 1);
    strncpy_s(ReqPk.UserName, id.c_str(), sizeof(ReqPk.UserName) - 1);

    char Buffer[1024] = { 0, };
    memcpy(Buffer, &ReqPk, sizeof(PACKET_REQ_SIGNUP));

    networkManager.SendPacket(Buffer, sizeof(PACKET_REQ_SIGNUP));
}

void UserService::Login(std::string userid, std::string password)
{
}

void UserService::Logout(std::string userid)
{
}



