#include <iostream>
#include "/usr/local/include/sqlite3.h"

constexpr const char * db_name = "test.db";

void test_insert_to_table(int rc, sqlite3 *db, sqlite3_stmt *stmt, char *errMsg){
    // Save SQL to create a table
    std::string sql = "CREATE TABLE PEOPLE ("  \
                      "ID INT PRIMARY KEY     NOT NULL," \
                      "NAME           TEXT    NOT NULL);";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);
    if (rc != SQLITE_OK){
        std::cout << errMsg << std::endl;
    }
    sql = "INSERT INTO PEOPLE ('ID', 'NAME') VALUES ('3','Jeff');";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);
    if (rc != SQLITE_OK){
        std::cout << errMsg << std::endl;
    }
    sql = "INSERT INTO PEOPLE ('ID', 'NAME') VALUES ('2','Dan');";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);
    if (rc != SQLITE_OK){
        std::cout << errMsg << std::endl;
    }
    sql = "INSERT INTO PEOPLE ('ID', 'NAME') VALUES ('1','Cara');";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);
    if (rc != SQLITE_OK){
        std::cout << errMsg << std::endl;
    }
    //sql = "SELECT * FROM 'PEOPLE';";nullptr
    //rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);

    /*sql = "DELETE FROM 'PEOPLE' WHERE ID = 3 OR ID = 2";
    rc = sqlite3_prepare(db, sql.c_str(), std::strlen(sql.c_str()), &stmt, nullptr);
    rc = sqlite3_step(stmt);
    rc = sqlite3_finalize(stmt);
    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg); */

    /*sql = "SELECT *FROM 'PEOPLE'";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);
    if (rc != SQLITE_OK){
        std::cout << errMsg << std::endl;
    }*/

    sqlite3_prepare_v2(db, "SELECT *FROM people", -1, &stmt, nullptr);
    int col_count = sqlite3_column_count(stmt);
    int row_count = 0;
    for (int var = 0; var < col_count; ++var) {
        std::cout << sqlite3_column_name(stmt, var);
        if(var  < col_count -  1) std::cout << ", " ;
    }
    //std::cout << " " << std::endl;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "" << std::endl;
        for (int var = 0; var < col_count; ++var) {
            std::cout << sqlite3_column_text(stmt, var);//  << std::endl;
            if(var  < col_count -  1) std::cout << ", ";
        }
        //std::cout << "";
    }


    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main(int argc, char *argv[]) {
    std::cout << "Sqlite3 library version: " << sqlite3_libversion() << std::endl;
    std::cout << "Sqlite3 source id:  " << sqlite3_sourceid() << std::endl;

    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;
    char *errMsg = 0;

    int rc = sqlite3_open(db_name, &db);
    if(rc == SQLITE_OK) {
        std::cout << "Database is open!" << std::endl;
    } else {
        std::cout << "Database not open -> error code: " << sqlite3_errstr(rc) << std::endl;
        sqlite3_close(db);
        exit(1);
    }

    test_insert_to_table(rc, db, stmt, errMsg);

    return 0;
}
