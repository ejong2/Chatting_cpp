#pragma once

#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/prepared_statement.h"

#include <string>
#include <memory>
#include <mutex>

#pragma comment (lib, "debug/mysqlcppconn.lib")

class DatabaseManager
{
private:
    const std::string DB_SERVERNAME = "tcp://127.0.0.1:3306";
    const std::string DB_USERNAME = "root";
    const std::string DB_PASSWORD = "1234";
    const std::string DB_DBNAME = "Chatting_cpp";

    sql::Driver* DB_DRIVER;
    std::unique_ptr<sql::Connection> DB_CONN;
    std::unique_ptr<sql::Statement> DB_STMT;
    std::unique_ptr<sql::PreparedStatement> DB_PSTMT;
    std::unique_ptr<sql::ResultSet> DB_RS;
    std::mutex DB_MUTEX;

public:
    DatabaseManager();
    ~DatabaseManager();

public:
    void RunDB();
};

