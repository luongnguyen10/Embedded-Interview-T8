#include<stdio.h>

const int i = 10;

void tong(int a, int b){
    int c;
    c = a + b;
    printf("Tong a va b: %d\n", c);
    printf(" Dia chi a: %p\n", &a);
    printf(" Dia chi b: %p\n", &b);
    printf(" Dia chi c: %p\n", &c);
}

int main(int argc, char const *argv[])
{   
    tong(6,9);
    // int a = 6; // 0xc1
    // int b = 9; // 0xc5
    // int c;       //0ca3
    printf("-----\n");
    tong(2,10);
    
    return 0;

}