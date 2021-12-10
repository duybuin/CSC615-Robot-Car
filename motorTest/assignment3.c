/**************************************************************
* Class: CSC-615-01 Fall 2021
* Name: Kyle Gilbert
* Student ID: 920913497
* Project: Assignment 3- Start Your Motor
*
* File: assignment3.c
*
* Description: This program runs a motor using an I2C Waveshare
* motor hat and a button. The motor begins only when the button 
* is pressed. The program runs the motor at 100% for a
* couple of seconds, gradually slows down to 15%, stops
* completely for at least a second, and then gradually speeds
* up to 100% in reverse. The program can be quit and the motor
* stops.
*
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "DEV_Config.h"
#include "PCA9685.h"

#define BUTTON 12 // pin 19, GPIO 10

// function prototypes
void forward();
void backward();
void stop();

// used if the program is quit
// while the motor is running
void Handler(int signo) {
  printf("Motor Stop\n");
  PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, 0);
  exit(0);
}

// move the motor forward at 100%, and
// reduce it to 15% over time
void forward() {
    int speed = 100;
    printf("Running forwards...\n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
    PCA9685_SetLevel(PCA_CHANNEL_1, 0);
    PCA9685_SetLevel(PCA_CHANNEL_2, 1);
    sleep(3); // wait 3 seconds
    while(speed > 15) {
      speed -= 5;
      PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
      printf("Current speed: %d\n", speed);
      delay(500);
    }
    stop();
}

// moves the motor in the backwards direction
// starting at 15% and slowly increasing to 100%
void backward() {
    printf("Running backwards...\n");
    int speed = 15;
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
    PCA9685_SetLevel(PCA_CHANNEL_1, 1);
    PCA9685_SetLevel(PCA_CHANNEL_2, 0);
    while (speed < 100) {
      speed += 5;
      PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, speed);
      printf("Current speed: %d\n", speed);
      delay(500);
    }
}

// stops the motor
void stop() {
    printf("Stopping motor...\n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, 0);
    sleep(2); // wait 2 seconds
    backward();
}

int main() {
    // setup
    wiringPiSetup();
    pinMode(BUTTON, INPUT);
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
    printf("Waiting for button to be pressed...\n");
    while(1) {
	// if button is clicked
        if (digitalRead(BUTTON) == HIGH) {
            printf("Button was pressed\n");
            break; // exit while loop
        }
    }

    signal(SIGINT, Handler);

    forward();

    // infinite loop for when the motor
    // reaches the backward function to
    // run until program is quit
    while(1) {

    }

    DEV_ModuleExit();

    return 0;
}
