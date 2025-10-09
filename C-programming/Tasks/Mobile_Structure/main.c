#include <stdio.h>
#include <string.h>

#include "Mobile.h"

int main() {
    struct Mobile myMobile;

    strcpy(myMobile.brand, "Samsung");
    strcpy(myMobile.model, "S24");
    myMobile.price = 49999.99;

    myMobile.mobileDimension.height = 160;
    myMobile.mobileDimension.width = 75;
    myMobile.mobileDimension.depth = 8;

    myMobile.mobileFrontSide.mobileFrontDimension.height = 160;
    myMobile.mobileFrontSide.mobileFrontDimension.width = 75;
    myMobile.mobileFrontSide.mobileFrontDimension.depth = 1;

    strcpy(myMobile.mobileFrontSide.frontDisplay.type, "SUPER AMOLED");
    myMobile.mobileFrontSide.frontDisplay.displayDimension.height = 150;
    myMobile.mobileFrontSide.frontDisplay.displayDimension.width = 70;
    myMobile.mobileFrontSide.frontDisplay.displayDimension.depth = 1;

    myMobile.mobileFrontSide.frontCamrea.megapixels = 12;
    myMobile.mobileFrontSide.frontCamrea.diameter = 5;

    myMobile.mobileRearSide.mobileBackDimension.height = 160;
    myMobile.mobileRearSide.mobileBackDimension.width = 75;
    myMobile.mobileRearSide.mobileBackDimension.depth = 1;

    myMobile.mobileRearSide.rearCamrea.megapixels = 50;
    myMobile.mobileRearSide.rearCamrea.diameter = 7;
    myMobile.mobileRearSide.flashLight.diameter = 2;

    myMobile.mobileLeftSide.leftSideDimension.height = 160;
    myMobile.mobileLeftSide.leftSideDimension.width = 2;
    myMobile.mobileLeftSide.leftSideDimension.depth = 1;

    strcpy(myMobile.mobileLeftSide.volumeButton.type, "Volume");
    myMobile.mobileLeftSide.volumeButton.buttonDimension.height = 20;
    myMobile.mobileLeftSide.volumeButton.buttonDimension.width = 5;
    myMobile.mobileLeftSide.volumeButton.buttonDimension.depth = 1;

    strcpy(myMobile.mobileLeftSide.simPort.type, "NanoSIM");
    myMobile.mobileLeftSide.simPort.portDimension.height = 15;
    myMobile.mobileLeftSide.simPort.portDimension.width = 10;
    myMobile.mobileLeftSide.simPort.portDimension.depth = 1;

    myMobile.mobileRightSide.rightSideDimension.height = 160;
    myMobile.mobileRightSide.rightSideDimension.width = 2;
    myMobile.mobileRightSide.rightSideDimension.depth = 1;

    strcpy(myMobile.mobileRightSide.powerButton.type, "Power");
    myMobile.mobileRightSide.powerButton.buttonDimension.height = 15;
    myMobile.mobileRightSide.powerButton.buttonDimension.width = 5;
    myMobile.mobileRightSide.powerButton.buttonDimension.depth = 1;

    myMobile.mobileTopSide.topSideDimension.height = 75;
    myMobile.mobileTopSide.topSideDimension.width = 2;
    myMobile.mobileTopSide.topSideDimension.depth = 1;

    strcpy(myMobile.mobileTopSide.headPhonePort.type, "3.5mm");
    myMobile.mobileTopSide.headPhonePort.portDimension.height = 10;
    myMobile.mobileTopSide.headPhonePort.portDimension.width = 5;
    myMobile.mobileTopSide.headPhonePort.portDimension.depth = 1;

    myMobile.mobileTopSide.microphone.diameter = 2;

    myMobile.mobileBottomSide.bottomSideDimension.height = 75;
    myMobile.mobileBottomSide.bottomSideDimension.width = 2;
    myMobile.mobileBottomSide.bottomSideDimension.depth = 1;

    myMobile.mobileBottomSide.sperker.no_of_speakers = 2;
    myMobile.mobileBottomSide.sperker.speakerDimension.height = 20;
    myMobile.mobileBottomSide.sperker.speakerDimension.width = 10;
    myMobile.mobileBottomSide.sperker.speakerDimension.depth = 1;

    strcpy(myMobile.mobileBottomSide.chargingPort.type, "USB-C");
    myMobile.mobileBottomSide.chargingPort.portDimension.height = 12;
    myMobile.mobileBottomSide.chargingPort.portDimension.width = 6;
    myMobile.mobileBottomSide.chargingPort.portDimension.depth = 1;

    printf("Mobile Brand: %s\n", myMobile.brand);
    printf("Model: %s\n", myMobile.model);
    printf("Price: Rs%f\n", myMobile.price);
    printf("Front Camera Megapixels: %d\n", myMobile.mobileFrontSide.frontCamrea.megapixels);
    printf("Rear Camera Megapixels: %d\n", myMobile.mobileRearSide.rearCamrea.megapixels);
    printf("Display Type: %s\n", myMobile.mobileFrontSide.frontDisplay.type);
    printf("Number of Speakers: %d\n", myMobile.mobileBottomSide.sperker.no_of_speakers);
    printf("Charging Port Type: %s\n", myMobile.mobileBottomSide.chargingPort.type);

    return 0;
}
