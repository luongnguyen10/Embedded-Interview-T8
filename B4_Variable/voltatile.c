#include <stdio.h>
#include <stdint.h>

volatile uint8_t data; // 0b000000

TASK1(){
    data = 0b11101;
    if (data == 0b00010000){
    }
}

TASK2(){
    if (data == 0b001000){

    }
}
int main(int argc, char const *argv[])
{
    volatile int a;

    while(1){
        data = readUSB(); // 0b00000010

    }
    return 0;
}

// compiler tối ưu biến int nếu giống nhau nó sẽ bỏ qua
// Biến volatile sẽ khai báo giúp compiler nhận biết biến này không cần tối ưu do thông thường các biến này có thể là một hàm đọc giá trị thời gian thực liên tục và tại mỗi thời điểm nó trả về kết quả khác nhau
// Volatile 