#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "PUBoardManager.h"
#include "PUBoard.h"
#include "College.h"
#include "boardDB.h"
#include "collegeDB.h"
#include "studentDB.h"
#include "evaluatorDB.h"
#include "marksDB.h"

enum choice
{
    infiniteLoop = 1,
    AddBoard,
    DisplayBoards,
    BoardLogin,
    CollegeLogin,
    StudentLogin,
    EvaluatorLogin,
    Exit
};

void menu()
{
    sqlite3 *db;
    PUBoardManager manager = {0};

    if (sqlite3_open("PUBoard.db", &db))
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        printf("Database opened successfully\n");
    }

    createPUBoardTable(db);
    createCollegeTable(db);
    createStudentTable(db);
    createEvaluatorTable(db);
    createStudentMarksTable(db);
    printf("All tables created successfully\n");


    loadBoardsFromDB(db, &manager);
    printf("Board data loaded\n");

    loadCollegesFromDB(db, &manager);
    printf("College data loaded\n");

    loadEvaluatorsFromDB(&manager, db);
    printf("Evaluators data loaded\n");

    for (int i = 0; i < manager.boardCount; i++)
    {
        PUBoard *board = manager.boards[i];
        College *college = board->collegeList;

        while (college)
        {
            loadStudentsFromDB(db, college);
            loadStudentMarksFromDB(college, db);
            college = college->nextCollege;
        }
    }
    printf("Student data loaded\n");

    int choice = 0;

    while (infiniteLoop)
    {
        printf("\n----- PU Management Menu -----\n");
        printf("1. Add Board Details\n");
        printf("2. Display Boards\n");
        printf("3. Board Login\n");
        printf("4. College Login\n");
        printf("5. Student Login\n");
        printf("6. Evaluator Login\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number\n");
            while (getchar() != '\n');
            continue;
        }

        choice++;

        switch (choice)
        {
        case AddBoard:
            addBoard(&manager, db);
            break;
        case DisplayBoards:
            displayBoards(&manager);
            break;
        case BoardLogin:
            boardLogin(&manager, db);
            break;
        case CollegeLogin:
            collegeLogin(&manager, db);
            break;
        case StudentLogin:
            studentLogin(&manager, db);
            break;
        case EvaluatorLogin:
            evaluatorLogin(&manager, db);
            break;
        case Exit:
            printf("Exiting the program\n");

            for (int i = 0; i < manager.boardCount; i++) {
                freeCollegeList(manager.boards[i]->collegeList);
                freeBoardEvaluators(manager.boards[i]);
                freePUBoard(manager.boards[i]);
            }

            free(manager.boards);
            sqlite3_close(db);
            return;

        default:
            printf("Invalid choice. Please try again\n");
            break;
        }
    }
}


