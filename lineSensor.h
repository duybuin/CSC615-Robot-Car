#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wiringPi.h>
#include "main.h"

#define LEFT 0
#define MIDDLE 2
#define RIGHT 3

void* line(void* args, int lineSensor);
void setLeftLineData(int data);
void setMidLineData(int data);
void setRightLineData(int data);
