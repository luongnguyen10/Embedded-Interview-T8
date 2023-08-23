#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    
    uint32_t array[] = {1,7,8,2,9};  // Cái này khai báo và fix ô nhớ cứng

    // Ví dụ khai báo một cái mảng mà không biết trước được độ lớn thì cần sử dụng cấp phát động
    uint8_t *ptr = (uint8_t *)malloc(5); // malloc hàm trả về một địa chỉ ( không biết kiểu dữ liệu gì => Cần ép kiểu)       
    // uint8_t 1byte => malloc 5 ô nhớ là 5 byte

    // nếu Kiểu dữ liệu là uint16_t thì cần 10 ô nhớ

    for (int  i = 0; i<5; i++){
        
        ptr[i] = 2*i;

    }

    for (int  i = 0; i<5; i++){
        
        printf("i: %p\n", &ptr[i]);

    }
    // Code vẫn chạy tuy nhiên, ở các địa chỉ mà không khai báo, Ram vẫn hiểu là chưa gán giá trị và sau này có thể gán giá trị khác và ảnh hưởng tới chương trình
    // Tổng quát thì cần khai báo như sau:

    // uint16_t *ptr = (uint16_t *)malloc(5 * sizeof(uint16_t));

    // Cách thay đổi kích thước của vùng nhớ này
    // realloc(< Địa chỉ cần thay đổi>, <Size của vùng nhớ mới>);

    ptr = (uint16_t *)realloc(ptr, 7 * sizeof(uint16_t));

    return 0;
}