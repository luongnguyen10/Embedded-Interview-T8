/*
* File: main.c
* Author: Nguyen Ba Luong
* Date: 06/09/2023
* Description: File the the day of week from the given date 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct money
{
    uint8_t day;
    uint8_t month;
    uint8_t year;
}Date;

typedef enum{
    CN = 0,
    T2 = 1,
    T3 = 2,
    T4 = 3,
    T5 = 4,
    T6 = 5,
    T7 = 6
} Weekday;



void DisplayDayofWeek(int dayofweek){

    switch(dayofweek){
        case CN:
            printf("CN\n");
            break;
        case T2:
            printf("T2\n");
            break;
        case T3:
            printf("T3\n");
            break;
        case T4:
            printf("T4\n");
            break;
        case T5:
            printf("T5\n");
            break;
        case T6:
            printf("T6\n");
            break;
        case T7:
            printf("T7\n");
            break;
    }
}

int leap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0) ? 1 : 0;
}

int numberOfDays(Date date, Date dateCurrent){
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
    int numberofyear = dateCurrent.year - date.year;
    if (numberofyear < 1) {
        numberofyear = dateCurrent.year - date.year;
    }
    else {

    }
    return result

} 

int main(){

    Date date = { 3, 1, 2000};

    Date dateCurrent = { 6, 9, 2023};

    int count = numberOfDays(date, dateCurrent);

    DisplayDayofWeek(0);

}