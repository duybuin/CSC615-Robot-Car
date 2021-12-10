/**************************************************************
* Class: CSC-615-01 Fall 2021
* Name: Kyle Gilbert
* Student ID: 920913497
* Project: Assignment 5- Follow in Line but Stop
*
* File: avoidanceSensor.c
*
* Description: This program uses both a line sensor and IR object
* sensor. If the line sensor detects a line, the console will print
* that. If the IR object sensor detects an obstructing object, that
* will also be printed in the console. This program uses multiple
* threads (one for each sensor) and updates the data in the main program.
*
**************************************************************/
#include "avoidanceSensor.h"

// initialize mutex
pthread_mutex_t objectMutex = PTHREAD_MUTEX_INITIALIZER;

void* avoidance(void* args) {
    pinMode(AVOIDANCESENSOR, INPUT);
    // infinite loop
    while(1) {
        // if sensor receives input, update data
        // and keep it safe/consistent with mutex
        if (digitalRead(AVOIDANCESENSOR) == HIGH) {
            pthread_mutex_lock(&objectMutex);
            setObjectData(0);
            pthread_mutex_unlock(&objectMutex);
        }
        if (digitalRead(AVOIDANCESENSOR) == LOW) {
            pthread_mutex_lock(&objectMutex);
            setObjectData(1);
            pthread_mutex_unlock(&objectMutex);
        }
    }
}
