#include <stdio.h>
#include <stdint.h>

void count(){
    static int i= 0;    // Khởi tạo địa chỉ  0x01 có gí trị = 0
    // Biến static chỉ tạo 1 lần và sử dụng cho toàn chươ chương trình, cho dù có chạy lại chương trình cũng không chạy lại
    // Tạo duy nhất một lần và tồn tại sử dụng hết vòng đời chương trình

    int x =0;           // Khởi tạo tại địa chỉ 0xc1 có giá trị = 0 
    // chạy lại chương trình này sẽ lại khởi tạo địa chỉ mới với giá trị 0

    printf("i = %d, x = %d\n", i, x);
    x++;
    i++;
}
int main(int argc, char const *argv[])
{
    count(); 

    count();
    
    count();
}

// Output
// i = 0, x = 0
// i = 1, x = 0
// i = 2, x = 0