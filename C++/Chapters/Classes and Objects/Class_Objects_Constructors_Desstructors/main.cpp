#include <iostream>

#include "car.h"
#include "book.h"
#include "laptop.h"
#include "bankaccount.h"
#include "student.h"
#include "teacher.h"
#include "mobile.h"
#include "restaurant.h"
#include "movie.h"
#include "song.h"
#include "creditcard.h"
#include "chair.h"
#include "camera.h"
#include "airplane.h"
#include "train.h"
#include "hospital.h"
#include "library.h"
#include "game.h"
#include "employee.h"
#include "watch.h"



using namespace std;

int main()
{
    Car myCar("Toyota","Corolla",50);
    myCar.refuel(20);
    myCar.drive(100);

    Book myBook("Panchatantra","VishnuSharma",100);
    myBook.read();
    myBook.info();

    Laptop myLaptop("hp",8);
    myLaptop.start();
    myLaptop.specs();

    BankAccount myAccount("Hruthik",1000,123456);
    myAccount.deposite(500);
    myAccount.showBalance();

    Student myStudent("Kris",111);
    myStudent.study();
    myStudent.displayStudent();

    Teacher myTeacher("Sandesh","Maths");
    myTeacher.introduce();
    myTeacher.teach();

    Mobile myMobile("CMF","2Pro",20000);
    myMobile.call(963214752);
    myMobile.message("hi...");

    Restaurant myRestaurant("PaakaShalaa",10);
    myRestaurant.serve();
    myRestaurant.seats();

    Movie myMovie("Su from So",145);
    myMovie.play();
    myMovie.details();

    Song mySong("Qatal","GR");
    mySong.play();
    mySong.stop();

    CreditCard myCard("14562","Hruthik");
    myCard.swipe();
    myCard.details();

    Chair myChair("Plastic",5);
    myChair.sit();
    myChair.info();

    Camera myCamera("Sony",450);
    myCamera.click();
    myCamera.record();

    Airplane myAirplane("Emirites",500);
    myAirplane.fly();
    myAirplane.land();

    Train myTrain("585674",8);
    myTrain.arrive();
    myTrain.depart();

    Hospital myHospital("Fortis",10);
    myHospital.admit();
    myHospital.info();

    Library myLibrary("Govt.",1000);
    myLibrary.borrow();
    myLibrary.status();

    Game myGame("BGMI","BattleRoyal");
    myGame.play();
    myGame.quit();

    Employee myEmployee("Ramesh",20000);
    myEmployee.work();
    myEmployee.showSalary();

    Watch myWatch("Titan",true);
    myWatch.showTime();
    myWatch.alarm();





    return 0;
}
