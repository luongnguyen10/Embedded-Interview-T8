#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG = 0; // 1 byte 00000000

typedef enum{
    AO          = 1 << 0,   // 0000 0001
    QUAN        = 1 << 1,   // 
    VAY         = 1 << 2,
    DAM         = 1 << 3,
    NHAN        = 1 << 4,
    VONG_TAY    = 1 << 5,
    GIAY        = 1 << 6,
    TUI         = 1 << 7,
}DO_DUNG_CA_NHAN;


int main(){

    
    GIO_HANG |= NHAN;

    GIO_HANG |= AO;

    GIO_HANG |= GIAY;

    GIO_HANG &= ~AO;

    if (GIO_HANG & NHAN ) printf("\nCo NHAN");
    
    return 0;

}