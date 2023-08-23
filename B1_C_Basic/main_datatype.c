#include <stdio.h>
#include <stdint.h>

uint8_t var;  // 8-bit tuong duong 2^8=256: 0-> 255

int8_t var_int;  // 8-bit tuong duong 2^8=256/2 : -128 -> 127

uint16_t var1;// 16-bit tuong duong 2^16 = 65536: tu 0-> 65535



int main(int argc, char const *argv[])
{
    var= 1;

    printf("Test: %d\n", var);
    
    var1= 65535;

    printf("Test: %d\n", var1);
    return 0;
}