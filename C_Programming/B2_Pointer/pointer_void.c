#include <stdio.h>
#include <stdint.h>
int main(int argc, char const *argv[])
{
    void *ptr;

    int a =10;
    ptr = &a;
    printf("Dia chi cua a: %p \n", ptr);

    double b = 10.2;

    char c = 'A';

//    char *ptr = &a; 

    return 0;
}