#include <stdio.h>
#include <stdint.h>

uint8_t vay = 1 << 1;  // 0000 0010

uint8_t quan = 1 << 2;  // 0000 0100

uint8_t gio_hang = 0;   // 0000 0000  Giỏ hàng không có gì hết

// Function to print the binary representation of a number
void printBits(unsigned int num, int numBits) {
    for (int i = numBits - 1; i >= 0; i--) {
        unsigned int mask = 1 << i;
        printf("%d", (num & mask) ? 1 : 0);
    }
}

int main(){

    // Thêm váy vào giỏ hàng
    gio_hang |= vay;
    
    // tương đương gio_hang = gio_hang || vay; // Thêm váy vào giở hàng
    // gio_hang =   0000 0000
    // vay =        0000 0010
    // gio_hang mới = 000 0010

    // Thêm quần vào giỏ hàng
    gio_hang |= quan; // 0000 0110

    // Bỏ váy ra khỏi giỏ hàng
    gio_hang &= ~vay;   
    // gio_hang =   0000 0110
    // vay đảo      1111 1101
    // gio_hang mới = 0000 0100


    // Lệnh in bit giỏ hàng
    int numBits = sizeof(gio_hang) * 8; // Number of bits in the variable (assuming unsigned int)

    printf("Binary representation of %u: ", gio_hang);
    printBits(gio_hang, numBits);
    printf("\n");


    return 0;

}