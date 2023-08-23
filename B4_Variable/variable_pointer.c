#include <stdio.h>
#include <stdint.h>

void count(){
    static int i= 0;    // Khởi tạo địa chỉ  0x01 có gí trị = 0
    *ptr = &i; 

    // printf("i = %d,\n", i, x);

    i++;
}
int main(int argc, char const *argv[])
{
    
    count(); 
    
    // *ptr =20;
    
    count();
    
    count();
}

// Output
// i = 0, x = 0
// i = 1, x = 0
// i = 2, x = 0