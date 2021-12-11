#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wiringPi.h>
#include "DEV_Config.h"
#include "PCA9685.h"

int leftLineSensor = 1;
int middleLineSensor = 1;
int rightLineSensor = 1;
// int objectData = 0;

// void setObjectData(int data);
