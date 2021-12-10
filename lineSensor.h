#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wiringPi.h>

#define LINESENSOR 2

void* line(void* args);
void setLineData(int data);
