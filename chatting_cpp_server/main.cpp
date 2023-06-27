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

#include "NetworkManager.h"

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

    NetworkManager networkManager;
    networkManager.RunServer();

    return 0;
}


