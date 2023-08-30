#include <stdio.h>
#include <stdint.h>

void tong(int a, int b){
    printf("Tong: %d va %d = %d \n", a, b, a+b);
} 

void hieu(int a, int b){
    printf("Hieu: %d va %d = %d \n", a, b, a-b);
}

void tinhToan( int a, int b, void (*ptr)(int a, int b)){
    printf("Ham tinh toan\n");
    ptr(a,b);
}

int main(int argc, char const *argv)
{
    tinhToan(5,6, &tong);

    tinhToan(7,3, &hieu);
    
    return 0;

}