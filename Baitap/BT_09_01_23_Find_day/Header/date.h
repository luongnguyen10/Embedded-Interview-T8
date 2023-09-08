/*
* File: date.h
* Author: Nguyen Ba Luong
* Date: 06/09/2023
* Description: This is a header file for demonstrating block-level comment
*/
#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct money
{
    int day;
    int month;
    int year;
}Date;

void displayDayofWeek(int count);

int isLeapYear(int year);

int countDayinMonth(Date dateCurrent);

int numberOfDays(Date dateOrigin, Date dateCurrent);

#endif
