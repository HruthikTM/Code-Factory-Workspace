#include <stdio.h>
#include <sqlite3.h>


int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;


    rc = sqlite3_open("test.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    } else {
        printf("Opened database successfully.\n");
    }

    // Create table SQL
    const char *sql_create_table = "CREATE TABLE IF NOT EXISTS PERSON("
                                   "ID INT PRIMARY KEY NOT NULL, "
                                   "NAME TEXT NOT NULL, "
                                   "AGE INT NOT NULL);";


    rc = sqlite3_exec(db, sql_create_table, 0, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully.\n");
    }


    const char *sql_insert = "INSERT INTO PERSON (ID, NAME, AGE) VALUES (1, 'Alice', 30);"
                             "INSERT INTO PERSON (ID, NAME, AGE) VALUES (2, 'Bob', 25);";

    rc = sqlite3_exec(db, sql_insert, 0, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Insert error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Records inserted successfully.\n");
    }


    const char *sql_select = "SELECT * FROM PERSON;";
    rc = sqlite3_exec(db, sql_select, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Select error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Select executed successfully.\n");
    }


    sqlite3_close(db);
    return 0;
}
