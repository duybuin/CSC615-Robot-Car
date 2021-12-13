#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wiringPi.h>

#define AVOIDANCESENSOR 0

void* avoidance(void* args);

// void setObjectData(int data);
