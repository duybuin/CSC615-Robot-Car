#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wiringPi.h>
#include "DEV_Config.h"
#include "PCA9685.h"

int lineData = 0;
int objectData = 0;

void setLineData(int data);

void setObjectData(int data);
