/**************************************************************
* Class: CSC-615-01 Fall 2021
* Name: Kyle Gilbert
* Student ID: 920913497
* Project: Assignment 5- Follow in Line but Stop
*
* File: lineSensor.c
*
* Description: This program uses both a line sensor and IR object
* sensor. If the line sensor detects a line, the console will print
* that. If the IR object sensor detects an obstructing object, that
* will also be printed in the console. This program uses multiple
* threads (one for each sensor) and updates the data in the main program.
*
**************************************************************/
#include "lineSensor.h"

// initialize the mutex
pthread_mutex_t lineMutex = PTHREAD_MUTEX_INITIALIZER;

void* line(void* args) {
    pinMode(LINESENSOR, INPUT);
    // infinite loop
    while(1) {
        // if sensor receives input
        if (digitalRead(LINESENSOR) == HIGH) {
            // update our data and keep it safe with mutex locking
            pthread_mutex_lock(&lineMutex);
            setLineData(0);
            pthread_mutex_unlock(&lineMutex);
        }
        // same as above but if the sensor isn't receiving HIGH input
        if (digitalRead(LINESENSOR) == LOW) {
            pthread_mutex_lock(&lineMutex);
            setLineData(1);
            pthread_mutex_unlock(&lineMutex);
        }
    }
}
