/*
* File: main.c
* Author: Nguyen Ba Luong
* Date: 06/09/2023
* Description: File the the day of week from the given date 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "date.h"

int main(){

    const Date dateOrigin = {1,1,2000}; // Tương ứng thứ 7

    Date dateCurrent = {7,9,2023};

    int count = numberOfDays(dateOrigin, dateCurrent);
    
    displayDayofWeek(count);

    return 0;
}