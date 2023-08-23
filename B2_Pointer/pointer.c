#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    int a =10;

    int *ptr = &a; // 0x01 Dia chi 

    printf("Dia chi a: %p\n", &a);

    printf("Gia tri cua bien ptr: %p\n", ptr);

    return 0;
}