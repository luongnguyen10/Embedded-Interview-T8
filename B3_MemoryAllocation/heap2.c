#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
void test1(){
    uint8_t array[5];
    printf("Dia chi: %p\n", array);
}

void test2(){
    uint8_t *array = (uint8_t *)malloc(5* sizeof(uint16_t));
    printf("Dia chi: %p\n", array);
    // free(array);
}

int main(){
    
    test1();  // Dia chi: 00000000005ffe6b
    test1(); // Dia chi: 00000000005ffe6b

    test2(); //Dia chi: 0000000000be1740
    test2(); // Dia chi: 0000000000be1780

    // Sự khác biệt là nếu xài cấp phát động thì vùng nhớ này sẽ không bị thu hồi sau khi dùng hàm Void
    // Nếu muốn thu hồi vùng nhớ thì sử dụng free(array);
    return 0;
}