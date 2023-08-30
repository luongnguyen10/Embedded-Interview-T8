#include<stdio.h>

#define CREATE_FUNC(name, cmd)  \
void name(){                    \
    printf("%s", (char*)#cmd);  \
}

// Thêm dấu # để hiểu là chuỗi 

CREATE_FUNC(test, This is test 1\n);

CREATE_FUNC(test2, This is test 2\n);

int main(int argc, char const *argv[])
{
    test();

    test2();
    
    return 0;

}