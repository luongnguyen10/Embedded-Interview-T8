#include <stdio.h>
#include <stdint.h>

typedef union{
    uint8_t var1[5];    
    uint8_t var2[3]; 
    uint8_t var3[2];   
} typeData;            


// Struct địa chỉ độc lập 

int main(int argc, char const *argv[])
{
    
    printf("size = %ld byte\n", sizeof(typeData));   

    typeData test;

    for ( int i = 0; i<5; i++){
        test.var1[i] = i; // 0 1 2 3 4
    }

    for ( int i = 0; i<3; i++){
        test.var2[i] = 3*i; // 0 3 6
    }

    for ( int i = 0; i<2; i++){
        test.var3[i] = 2*i; //  0 2 
    }

    for ( int i = 0; i < 5; i++){
        printf("%d\n", test.var1[i]);  
    }
    
    return 0;

}