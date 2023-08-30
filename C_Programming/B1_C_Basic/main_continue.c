#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    for (int  i = 0 ; i< 10;i++){
        if (i ==5){
            continue;
        }
        // Nếu i mà == 5 thì sẽ không in dòng lệnh sau, mà bỏ qua
        printf("i = %d\n",i);
    }
    return 0;
}