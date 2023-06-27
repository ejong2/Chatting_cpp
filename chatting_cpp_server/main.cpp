#define _WINSOCK_DEPRECATED_NO_WARNINGS
//--C++ Header----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
//--Plugin Header-------------------------------------------------------------
#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/prepared_statement.h"
//--Plugin Library------------------------------------------------------------
#pragma comment (lib, "debug/mysqlcppconn.lib")
#pragma comment (lib, "WS2_32.lib")
//--Network-------------------------------------------------------------------
#include <WinSock2.h> 
#include <Windows.h>
#include <process.h>

WSAData                      NET_WSADATA = { 0, };
SOCKET                       NET_SERVERSOCKET = NULL;
SOCKADDR_IN                  NET_SERVERADDR = { 0, };
const char* NET_SERVER_IPV4 = "127.0.0.1";
const int                    NET_SERVER_PORT = 5001;
const int                    NET_PACKET_SIZE = 512;
std::mutex                   NETWORK_MUTEX;
//--DBMS----------------------------------------------------------------------
const std::string            DB_SERVERNAME = "tcp://127.0.0.1:3306";
const std::string            DB_USERNAME = "root";
const std::string            DB_PASSWORD = "1234";
const std::string            DB_DBNAME = "Chatting_cpp";
sql::Driver* DB_DRIVER = nullptr;
std::unique_ptr<sql::Connection> DB_CONN;
std::unique_ptr<sql::Statement> DB_STMT;
std::unique_ptr<sql::PreparedStatement> DB_PSTMT;
std::unique_ptr<sql::ResultSet> DB_RS;
std::mutex                   DB_MUTEX;
//--MainProgram---------------------------------------------------------------
bool                         G_PROGRAMRUNNING = true;

int main()
{
    std::cout << "Chatting_cpp Server v20230627" << std::endl;

    try
    {
        DB_DRIVER = get_driver_instance();
        DB_CONN.reset(DB_DRIVER->connect(DB_SERVERNAME, DB_USERNAME, DB_PASSWORD));
        DB_CONN->setSchema(DB_DBNAME);
        std::cout << "[SYS] MySQLDB [" << DB_SERVERNAME << "] Connected!" << std::endl;
    }
    catch (sql::SQLException& e)
    {
        std::cout << "[ERR] DB_CONNection Error Occurred. ErrorMsg : " << e.what() << std::endl;
        exit(-11);
    }

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

    while (G_PROGRAMRUNNING)
    {
        SOCKADDR_IN ClientAddr = { 0, };
        int szClientAddr = sizeof(ClientAddr);
        SOCKET ClientSocket = accept(NET_SERVERSOCKET, (SOCKADDR*)&ClientAddr, &szClientAddr);
        if (ClientSocket == INVALID_SOCKET)
        {
            closesocket(ClientSocket);
            continue;
        }
        // 立加茄 家南 ID 免仿
        std::cout << "[SYS] ClientSocket [" << ClientSocket << "] Connected!" << std::endl;
    }
    std::cout << "[SYS] ServerSocket [" << NET_SERVERSOCKET << "] Listen Finished!" << std::endl;
    closesocket(NET_SERVERSOCKET);

    WSACleanup();
    return 0;
}


