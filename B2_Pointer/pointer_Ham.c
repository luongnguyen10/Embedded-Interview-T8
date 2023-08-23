#include <stdio.h>
#include <stdint.h>

void tong(int a, int b){
    printf("Tong: %d va %d = %d \n", a, b, a+b);
} 

void hieu(int a, int b){
    printf("Hieu: %d va %d = %d \n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}

int main(int argc, char const *argv)
{
    void (*ptr)(int, int);

    ptr = &tong;

    ptr(9,7);
    printf("%d \n", ptr);
    
    // ptr = &hieu;

    // ptr(14,6);
    // printf("%d \n", ptr);

    int (*ptrTich)(int, int) = &tich;

    printf("Tich: %d\n ", ptrTich(5,5));

    return 0;

}