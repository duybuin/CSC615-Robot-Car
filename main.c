/**************************************************************
* Class: CSC-615-01 Fall 2021
* Name: Kyle Gilbert
* Student ID: 920913497
* Project: Car Project
*
* File: main.c
*
*
**************************************************************/

#include "main.h"
#include "avoidanceSensor.h"
#include "lineSensor.h"

// function prototypes
void forward(int speed, int motor);
void backward(int speed, int motor);
void stop();

// used if the program is quit
// while the motor is running
void Handler(int signo) {
  printf("Motor Stop\n");
  PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, 0);
  PCA9685_SetPwmDutyCycle(PCA_CHANNEL_5, 0);
  exit(0);
}
// 0 is left motor, 1 is right motor
void forward(int speed, int motor) {
    printf("Running forwards...\n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
    PCA9685_SetLevel(PCA_CHANNEL_1, 0);
    PCA9685_SetLevel(PCA_CHANNEL_2, 1);

    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_5, speed);
    PCA9685_SetLevel(PCA_CHANNEL_3, 0);
    PCA9685_SetLevel(PCA_CHANNEL_4, 1);
}

// 0 is left motor, 0 is right motor
void backward(int speed, int motor) {
    printf("Running backwards...\n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
    PCA9685_SetLevel(PCA_CHANNEL_1, 1);
    PCA9685_SetLevel(PCA_CHANNEL_2, 0);
}

// stops the motor
void stop() {
    printf("Stopping motor...\n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, 0);
    sleep(2); // wait 2 seconds
}

// functions for setting data
/*void setLineData(int data) {
    lineData = data;
}*/

/*void setObjectData(int data) {
    objectData = data;
}*/

int main() {
    // setup
    wiringPiSetup();
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);

    // pthread_t thread1, thread2;
    // create thread for line sensor
    // pthread_create(&thread1, NULL, &line, NULL);
    // create thread for IR object sensor
    // pthread_create(&thread2, NULL, &avoidance, NULL);
    // infinite loop until program is terminated
    /* while(1) {
        // if line thread received input and set our variable
        if (lineData == 1) {
            printf("line detected\n");
        }
        // same as above but for the IR object sensor
        if (objectData == 1) {
            printf("object detected\n");
        }

    }*/

    signal(SIGINT, Handler);

    forward(100, 1);

    // infinite loop for when the motor
    // reaches the backward function to
    // run until program is quit
    while(1) {

    }

    DEV_ModuleExit();

    return 0;
}
