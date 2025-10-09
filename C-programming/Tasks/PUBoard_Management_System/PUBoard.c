#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "PUBoardManager.h"



void addBoard(PUBoardManager *manager, sqlite3 *db)
{
    if (manager == NULL)
    {
        printf("Board manager is not properly initialized\n");
        return;
    }

    if (manager->boardCount >= MAX_BOARDS)
    {
        printf("Maximum number of boards reached\n");
        return;
    }

    PUBoard *board = (PUBoard *)malloc(sizeof(PUBoard));
    if (!board)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\n--- Add Board Details ---\n");

    char tempBoardName[500];
    char tempBoardID[500];
    char tempBoardPassword[500];

    printf("Enter Board Name: ");
    getchar();
    fgets(tempBoardName, sizeof(tempBoardName), stdin);
    tempBoardName[strcspn(tempBoardName, "\n")] = '\0';
    board->boardName = (char*) malloc(strlen(tempBoardName) + 1);
    strcpy(board->boardName, tempBoardName);


    printf("Set User ID: ");
    fgets(tempBoardID, sizeof(tempBoardID), stdin);
    tempBoardID[strcspn(tempBoardID, "\n")] = '\0';
    board->userId = (char *)malloc(strlen(tempBoardID) + 1);
    strcpy(board->userId, tempBoardID);


    printf("Set Password: ");
    fgets(tempBoardPassword, sizeof(tempBoardPassword), stdin);
    tempBoardPassword[strcspn(tempBoardPassword, "\n")] = '\0';
    board->password = (char *)malloc(strlen(tempBoardPassword) + 1);
    strcpy(board->password, tempBoardPassword);

    board->collegeList = NULL;
    board->evaluatorCount = 0;

    manager->boards[manager->boardCount] = board;
    manager->activeBoard = board;
    manager->boardCount++;

    insertPUBoard(db, board);


    printf("Board details added successfully\n");
}



void displayBoards(PUBoardManager *manager)
{
    if (!manager || manager->boardCount <= 0)
    {
        printf("\nNo boards available to display\n");
        return;
    }

    printf("\nCurrent Boards:\n");
    for (int i = 0; i < manager->boardCount; i++)
    {
        if (manager->boards[i])
        {
            printf("%d. %s\n", i + 1, manager->boards[i]->boardName);
        }
        else
        {
            printf("NO Boards Avaliable\n");
        }

    }
}



void boardLogin(PUBoardManager *manager,sqlite3 *db)
{
    if (manager->boardCount == 0)
    {
        printf("\nNo boards available. Please add a board first\n");
        return;
    }

    char enteredUserId[20];
    char enteredPassword[20];

    printf("\n--- Board Login ---\n");
    printf("Enter User ID: ");
    scanf("%s", enteredUserId);
    printf("Enter Password: ");
    scanf("%s", enteredPassword);

    int boardIndex = -1;

    for (int i = 0; i < manager->boardCount; i++)
    {
        if (strcmp(enteredUserId, manager->boards[i]->userId) == 0)
        {
            boardIndex = i;
            break;
        }
    }

    if (boardIndex == -1)
    {
        printf("Board ID not found\n");
        return;
    }

    if (strcmp(enteredPassword, manager->boards[boardIndex]->password) != 0)
    {
        printf("Incorrect password\n");
        return;
    }

    manager->activeBoard = manager->boards[boardIndex];

    printf("\nLogin successful for Board: %s\n", manager->activeBoard->boardName);

    boardMenuHandler(manager,db);
}


enum choice
{
    infiniteLoop = 1,
    AddCollegeDetails,
    DisplayCollegeDetails,
    DisplayCollegeWisePassPercentage,
    AddEvaluator,
    Logout
};

void boardMenuHandler(PUBoardManager *manager,sqlite3 *db)// function naming
{
    int choice = 0;

    while (infiniteLoop)
    {
        printf("\n--- Board Menu ---\n");
        printf("1. Add College Details\n");
        printf("2. Display College Details\n");
        printf("3. Display College-wise Pass Percentage\n");
        printf("4. Add Evaluator\n");
        printf("5. Logout\n");

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
        case AddCollegeDetails:
            addCollegeDetails(manager,db);
            printf("College Details Added Successfully\n");
            break;
        case DisplayCollegeDetails:
            displayCollegeDetails(manager);
            break;
        case DisplayCollegeWisePassPercentage:
            displayCollegeWisePassPercentage(manager);
            break;
        case AddEvaluator:
            addEvaluator(manager,db);
            break;
        case Logout:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice. Please try again\n");
        }
    }
}




void freePUBoard(PUBoard *board)
{
    if (board == NULL)
        return;

    if (board->boardName)
        free(board->boardName);
    if (board->userId)
        free(board->userId);
    if (board->password)
        free(board->password);

    free(board);
}


void freePUBoardManager(PUBoardManager *manager)
{
    if (!manager)
        return;

    for (int i = 0; i < manager->boardCount; i++)
    {
        if (manager->boards[i])
        {
            freeBoardEvaluators(manager->boards[i]);
            freePUBoard(manager->boards[i]);
        }
    }

    free(manager->boards);
    free(manager);
}




























