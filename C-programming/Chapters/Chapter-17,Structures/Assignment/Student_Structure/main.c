#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 450

struct student {
    int rollno;
    char name[20];
    char dept[20];
    char course[20];
    int yearofjoining;
};

void printStudentsByYear(struct student students[], int totalStudents, int year);
void printStudentByRoll(struct student students[], int totalStudents, int rollNumber);

int main() {
    struct student students[MAX_STUDENTS];
    int totalStudents, actualStudents = 0;
    int year, roll;

    printf("Enter number of students (max 450): ");
    scanf("%d", &totalStudents);

    if (totalStudents > MAX_STUDENTS || totalStudents < 1) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 0; i < totalStudents;) {
        struct student temp;
        int isDuplicate = 0;

        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &temp.rollno);
        printf("Name: ");
        scanf(" %s", temp.name);
        printf("Department: ");
        scanf(" %s", temp.dept);
        printf("Course: ");
        scanf(" %s", temp.course);
        printf("Year of Joining: ");
        scanf("%d", &temp.yearofjoining);


        for (int j = 0; j < actualStudents; j++) {
            if (
                temp.rollno == students[j].rollno &&
                strcmp(temp.name, students[j].name) == 0 &&
                strcmp(temp.dept, students[j].dept) == 0 &&
                strcmp(temp.course, students[j].course) == 0 &&
                temp.yearofjoining == students[j].yearofjoining
                ) {
                printf("Warning: Duplicate student (all fields match). Please re-enter details.\n");
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            students[actualStudents++] = temp;
            i++;
        }
    }

    printf("\nEnter a year to search for students who joined in that year: ");
    scanf("%d", &year);
    printStudentsByYear(students, actualStudents, year);

    printf("\nEnter roll number to search for student details: ");
    scanf("%d", &roll);
    printStudentByRoll(students, actualStudents, roll);

    return 0;
}

void printStudentsByYear(struct student students[], int totalStudents, int year) {
    int found = 0;
    printf("\nStudents who joined in %d:\n", year);
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].yearofjoining == year) {
            printf("Roll No: %d | Name: %s | Dept: %s | Course: %s\n",
                   students[i].rollno, students[i].name,
                   students[i].dept, students[i].course);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found for year %d.\n", year);
    }
}

void printStudentByRoll(struct student students[], int totalStudents, int rollNumber) {
    int found = 0;
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollno == rollNumber) {
            if (!found) {
                printf("\nDetails for Roll Number %d:\n", rollNumber);
            }
            found = 1;
            printf("Name: %s | Dept: %s | Course: %s | Year: %d\n",
                   students[i].name, students[i].dept,
                   students[i].course, students[i].yearofjoining);
        }
    }
    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}
