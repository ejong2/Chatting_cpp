#include "DatabaseManager.h"

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
}

void DatabaseManager::RunDB()
{
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
}
