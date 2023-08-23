#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint32_t var;    // 8 bit = 1 byte
    uint8_t var2;  // 32 bit = 4 byte
    uint8_t var3;   // 8 bit = 1 byte
} typeData;

// Tổng dung lượng là 8 byte

// Một lần quét dựa vào kiến trúc Vi xử lý
// Với riêng compiler Gcc, với mỗi lần quét lấy kích thước kiểu dữ liệu member lớn nhất làm size chung của những member khác
// Tính toán sử dụng thứ tự member hợp lý để tối ưu dung lượng

typedef struct{
    uint8_t var1[5];    //   4 byte + 1 byte
    uint16_t var2[2];  // 2 byte * 2
    uint32_t var3[2];   //  4 byte *2
} typeData2;            // Tổng dung lượng là 20 byte


// Struct địa chỉ độc lập 

int main(int argc, char const *argv[])
{
    
    printf("size = %ld byte\n", sizeof(typeData2));   // Kết quả là 8 byte

    typeData2 test;

    printf("Dia chi test     : %p\n", &test);       //00000000005ffe80

    printf("Dia chi test.var1: %p\n", &test.var1);  //00000000005ffe80

    printf("Dia chi test.var2.0: %p\n", &test.var2[0]);  //00000000005ffe86

    printf("Dia chi test.var2.1: %p\n", &test.var2[1]);  //00000000005ffe86

    printf("Dia chi test.var3: %p\n", &test.var3);  //00000000005ffe8c
    return 0;
}