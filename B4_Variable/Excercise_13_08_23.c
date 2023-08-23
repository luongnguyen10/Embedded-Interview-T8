#include <stdint.h>

void test1(){
    printf("Thong tin sinh vien");
}

void test2(){
    printf("SĐT");
}

void test3(){
    printf("MSSV");
}

#define OPTION(option) option 
#define NAME(ten) ten 
#define VALUE(value) value 

#define Display(key,name) printf("%d: %s/n", key, name)

int main(int argc, char const *argv[])
{
    void *func[] = {&test1, &test2, &test3};

    return 0;
}

