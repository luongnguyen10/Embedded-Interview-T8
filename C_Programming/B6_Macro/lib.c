#include <stdio.h>

#define STM32F103   0
#define ATMEGA      1
#define PIC16F887   2

// Các thanh ghi ở đây mang tính ví dụ (ALU, AIT)


#if MCU == STM32F103

void Blinkled(){
    int DRC= 1;
    DRC = !DRC;
    delay(1000);
}

#elif MCU == ATMEGA

void Blinkled(){
    ALU = !ALU;
    delay(1000);
}

#elif MCU == PIC16F887

void Blinkled(){
    int AIT= 1;
    AIT = !AIT;
    delay(1000);
}

#endif