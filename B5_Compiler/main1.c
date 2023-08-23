#include <stdio.h>
#include "test.c"

#define MAX 20
#define SUM(a,b) a+b

// This is function test

void display(){
    printf("This is display main.c\n");
}

int main(int argc, char const *argv[])
{   
    display();
    test();
    return 0; 
}