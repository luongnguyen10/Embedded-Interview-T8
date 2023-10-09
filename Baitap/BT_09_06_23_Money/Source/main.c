/*
* File: main.c
* Author: Nguyen Ba Luong
* Date: 08/09/2023
* Description: Reverse the whole string  
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// #include "money.h"

const char *digitToWord(int digit) {
    const char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return words[digit];
}

int takeSize(char array[]){
    int i = 0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}


int main(){
    
    char number[] = "123456";// 120 000 123 822
    int size = takeSize(number);
    printf("\n%d\n", size);
    
    return 0;
}