#include "Sql_Reader.h"
#include "EmployeeDetails.h"
#include <fstream>


Sql_Reader::Sql_Reader()
{
    cout << "SQL Reader Constructor" << endl;
}

Sql_Reader::~Sql_Reader()
{
    cout << "SQL Reader Destructor" << endl;
}

void Sql_Reader :: readFile(list<EmployeeDetails*>& employeeDetailsList)
{

    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT empId, empName, empDesg FROM employees;";

    if(sqlite3_open("employee.db",&db) == SQLITE_OK)
    {
        if(sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            while(sqlite3_step(stmt) == SQLITE_ROW)
            {
                string id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                string desg = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

                EmployeeDetails *e = new EmployeeDetails(id, name, desg);
                employeeDetailsList.push_back(e);
            }

            sqlite3_finalize(stmt);
        }

        else
        {
            cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        }

        sqlite3_close(db);
    }

    else
    {
        cerr << "Can't open the DB: " << sqlite3_errmsg(db) << endl;
    }

}
