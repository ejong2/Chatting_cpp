#include "NetworkManager.h"
#include "DatabaseManager.h"

int main()
{
    std::cout << "Chatting_cpp Server v20230627" << std::endl;

    DatabaseManager dbManager;
    dbManager.RunDB();

    NetworkManager networkManager;
    networkManager.RunServer();

    return 0;
}


