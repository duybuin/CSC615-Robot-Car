#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>

#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR1 2
#define MOTOR2 3
#define MOTOR3 4
#define MOTOR4 5

void Handler(int signo) {
  printf("Motor Stop\n");
  softPwmWrite(MOTOR1, 0);
  softPwmWrite(MOTOR2, 0);
  softPwmWrite(MOTOR3, 0);
  softPwmWrite(MOTOR4, 0);
  exit(0);
}

int main() {
    wiringPiSetup();
    pinMode(MOTOR1, SOFT_PWM_OUTPUT);
    pinMode(MOTOR2, SOFT_PWM_OUTPUT);
    pinMode(MOTOR3, SOFT_PWM_OUTPUT);
    pinMode(MOTOR4, SOFT_PWM_OUTPUT);

    softPwmCreate(MOTOR1, 0, 100);
    softPwmCreate(MOTOR2, 0, 100);
    softPwmCreate(MOTOR3, 0, 100);
    softPwmCreate(MOTOR4, 0, 100);

    signal(SIGINT, Handler);

    softPwmWrite(MOTOR1, 100);
    softPwmWrite(MOTOR2, 100);
    softPwmWrite(MOTOR3, 100);
    softPwmWrite(MOTOR4, 100);

    while(1) {

    }

    DEV_ModuleExit();

    return 0;
}