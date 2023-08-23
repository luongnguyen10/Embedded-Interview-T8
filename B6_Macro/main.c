#include <stdio.h>
#define MCU PIC16F887 // THAY ĐỔI MACRO Ở ĐÂY CHƯƠNG TRÌNH SẼ BUILD THEO THƯ VIỆN IF ELSE
#include "lib.c"


int main(int argc, char const *argv[])
{
    while (1)
    {
        /* code */
        Blinkled();
    }
        
    return 0;
}

