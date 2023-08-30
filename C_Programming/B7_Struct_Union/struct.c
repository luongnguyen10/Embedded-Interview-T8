#include<stdio.h>

typedef struct 
{
    /* data */
    int x;
    int y;
    int z;
} typeData;

int main(int argc, char const *argv[])
{
    // typeData Data = {1,2,3};
    
    typeData Data;
    
    Data.x = 30;

    Data.y = 50;

    Data.z = 2;

    printf("x = %d, y = %d, z = %d \n", Data.x, Data.y, Data.z);

    return 0;
}