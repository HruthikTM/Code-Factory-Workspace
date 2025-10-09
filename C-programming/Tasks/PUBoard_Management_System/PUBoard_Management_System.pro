TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        College.c \
        Evaluator.c \
        Marks.c \
        Menu.c \
        PUBoard.c \
        Student.c \
        Student_details.c \
        boardDB.c \
        collegeDB.c \
        evaluatorDB.c \
        main.c \
        marksDB.c \
        sqlite3.c \
        studentDB.c \
        subjectData.c

HEADERS += \
    College.h \
    DateOfBirth.h \
    Evaluator.h \
    Marks.h \
    PUBoard.h \
    PUBoardManager.h \
    Result.h \
    Stream.h \
    Student.h \
    StudentAcademicDetails.h \
    StudentPersonalDetails.h \
    Subject.h \
    boardDB.h \
    collegeDB.h \
    evaluatorDB.h \
    marksDB.h \
    sqlite3.h \
    sqlite3ext.h \
    studentDB.h \
    subjectData.h
