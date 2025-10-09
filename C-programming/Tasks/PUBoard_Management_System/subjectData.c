#include <stdio.h>
#include <string.h>
#include "Subject.h"

static Subject globalSubjects[] = {
    {"PHY", "Physics"},
    {"CHE", "Chemistry"},
    {"MAT", "Mathematics"},
    {"BIO", "Biology"},
    {"ACC", "Accountancy"},
    {"BST", "BusinessStudies"},
    {"ECO", "Economics"},
    {"COM", "Commerce"},
    {"HIS", "History"},
    {"POL", "PoliticalScience"},
    {"SOC", "Sociology"},
    {"PSY", "Psychology"},
};

static int subjectCount = sizeof(globalSubjects) / sizeof(globalSubjects[0]);

Subject* getGlobalSubjects() {
    return globalSubjects;
}

int getSubjectCount() {
    return subjectCount;
}

