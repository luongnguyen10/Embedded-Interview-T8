#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    int i = 20;

    if (i>20){
        printf("i > 20\n");
    } else if(i==20){
        printf("i = 20\n");
    } else {
        printf("i < 20\n");
    }
    return 0;
}
