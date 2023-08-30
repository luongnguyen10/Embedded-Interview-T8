#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    int  i = 0;
    do 
    {
        printf("i = %d\n", i);
        i++;
    } while (i==0);
    
    return 0;
}