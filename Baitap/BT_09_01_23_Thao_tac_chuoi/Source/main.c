/*
* File: main.c
* Author: Nguyen Ba Luong
* Date: 08/09/2023
* Description: Reverse the whole string  
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "string.h"

int main(){
    // char string[] = "nhat hang tuan nam nhat hang nhat nam bao quoc nam";
    char string[] = "nhat hang tuan";

    printf("Original string: %s\n", string);

    reverseWords(string);

    printf("Reversed string: %s\n", string);

    return 0;
}