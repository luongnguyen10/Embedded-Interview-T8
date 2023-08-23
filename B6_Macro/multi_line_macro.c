#include<stdio.h>

#define CREATE_FUNC(name, cmd)  \
void name(){                    \
    printf("%s", (char*)#cmd);  \
}

CREATE_FUNC(test, This is test 1\n);

CREATE_FUNC(test2, This is test 2\n);

// Thêm dấu # để hiểu là chuỗi 

#define CREATE_VARIABLE(name)  \
int name__##var;                \
int name__##var2;               \
int name__##var3;               

// Thêm dấu ## để Nối 2 chuỗi với nhau

#define VAR(...) __VA_ARGS__

int main(int argc, char const *argv[])
{
    // test();

    // test2();
    
    // CREATE_VARIABLE(test);

    // VAR(int a, int b, int c;); // Hiển thị cái gì nhập vào 

    return 0;

}