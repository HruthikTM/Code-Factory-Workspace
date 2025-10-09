#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "Student.h"



int main()
{
    sqlite3 *db;

    int rc = sqlite3_open("student.db", &db);
    if(rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }
    else
    {
        printf("Opened database successfully.\n");
    }

    createStudentTable(db);

    Student s1 = {6,"tyu",3333};
    insertStudent(db,s1);
    Student s2 = {7,"poiu",8545};
    insertStudent(db,s2);

    readStudents(db);

    updateStudentPhone(db,10,74125);

    readStudents(db);

    deleteStudent(db,2);

    readStudents(db);

    sqlite3_close(db);

    return 0;
}
