# EMBEDDED INTERVIEW T8

<details> <summary> C BASIC </summary> 

## Lesson 1: C Basic

### 1. Datatype
- Khai báo kiểu dữ liệu rất quan trọng, không được thiếu, không được thừa 
- Các kiểu dữ liệu unsign: uint8_t, uint16_t, uint32_t, uint64_t

- VD kích thước của biến sau:
    uint8_t var; có 8-bit tuong duong 2^8=256: 0-> 255
    int8_t var; có 8-bit tuong duong 2^8=256/2 : -128 -> 127
    uint16_t var1; có 16-bit tuong duong 2^16 = 65536: tu 0-> 65535

### 2. TypeDef
- Một kiểu định nghĩa

Ví dụ sau định nghĩa lại kieuInt là kiểu int (Thay thế một tên khác nhưng bản chất vẫn là int)

```cpp  
typedef int kieuInt;

int main(int argc, char const *argv[])
{
    kieuInt bienA = 28;
    printf(" Test: %d\n", bienA);

    return 0;
}
```
### 3. Câu lệnh điều kiện
#### If Else

```cpp
    int i = 20;

    if (i>20){
        printf("i > 20\n");
    } else if(i==20){
        printf("i = 20\n");
    } else {
        printf("i < 20\n");
    }
```

#### Switch Case
- Cách hoạt động
    - Kiểm tra giá trị đầu tiên
    - Nếu case tương ứng với giá trị sẽ thực thi lệnh và break để thoát vòng lặp
    - 
```cpp
    int i = 0; 

    switch (i){
    case 1:
        printf("Case 1\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
    default: 
        printf("Case ngoai le\n");
        break;
    }
```

- Trường hợp đặc biệt nếu i bằng 1 hoặc 2 đều print giá trị ở case 2
- break giúp thoát ra khỏi vòng lặp

```cpp
    int i = 0; 

    switch (i){
    case 1:
        
    case 2:
        printf("Case 2\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
    default: 
        printf("Case ngoai le\n");
        break;
    }
```
### 4. Enum
- Cách thiết kế switch case với enum
- enum gán giá trị thằng sau lớn hơn giá trị trước 1 đơn vị
```cpp
typedef enum {
    THANG_MOT, // 0
    THANG_HAI, // 1
    THANG_BA,
    THANG_TU,
    THANG_NAM,
    THANG_SAU,
    THANG_BAY,
    THANG_TAM, // 7
    THANG_CHIN =20, // Neu gan gia tri khac thì thằng tiếp theo sẽ tăng 1 giá trị
    THANG_MUOI,  // 21
    THANG_MUOI_MOT, // 22
    THANG_MUOI_HAI
} typeThang; // Dinh nghia lai bang label thang

int main(int argc, char const *argv[])
// int main() 
{
    typeThang thang = THANG_MOT;
    
    switch (thang)
    {
        case THANG_MOT:
        case THANG_BA:
        case THANG_NAM:
        case THANG_BAY:
        case THANG_TAM:
        case THANG_MUOI:
        case THANG_MUOI_HAI:
            printf("Thang co 31 ngay\n");
            break;
        case THANG_TU:
        case THANG_SAU:
        case THANG_CHIN:
        case THANG_MUOI_MOT:
            printf("Thang co 30 Ngay\n");
            break;
        case THANG_HAI:
            printf("Thang co 28 Ngay\n");
            break;
        default: 
            printf("Case ngoai le\n");
            break;
    }
    return 0;
}
```

### 6. Loop
#### 6.1 For
Cú pháp
for ( < Khai báo giá trị ban đầu>, < điều kiện  (đúng thì chạy chương trình)>, <Toán tử, thực hiện cuối cùng> )

```cpp
    int main(int argc, char const *argv[])
{
    for (int  i = 0 ; i< 10;i++ ){
        printf("i = %d\n",i);
        
    }
    return 0;
}
```

- Cách viết khác
```cpp
int main(int argc, char const *argv[])
{
    int i = 0;
    for (; i< 10; ){
        printf("i = %d\n",i);
        i++;
    }
    return 0;
}
```
##### Continue
- Bỏ qua chương trình

```cpp
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
```
#### 6.2 While
| While |  Do - While  |
|:-----:|:--------:|
| Chương trình kiểm tra điều kiện trước rồi với chạy chương trình   | Chương trình chạy trước 1 lần rồi mới kiểu tra điều kiện| 

```cpp
int main(int argc, char const *argv[])
{
    int  i = 0;

    while (i<10)
    {
        printf("i = %d\n", i);
        i++;
    }
    return 0;
}
```
#### 6.3 Do - While
- Chương trình chạy trước một lần rồi mới kiểm tra điều kiện
```cpp
int main(int argc, char const *argv[])
{
    int  i = 0;
    do 
    {
        printf("i = %d\n", i);
        i++;
    } while (i==0)
    return 0;
}
```

## Lesson 2: Pointer
### 1. Pointer Giá trị 
```cpp
int a = 10; // Giá trị a có địa chỉ là 0x01

``` 
| Địa chỉ |  Giá trị  |
|:-----:|:--------:|
| 0x01| 10| 

```cpp
int *ptr = 0x01 ; // Địa chỉ là 0x01 có giá trị là kiểu dữ liệu int

&a = 0x01; // Lấy địa chỉ
```

```cpp
int main(int argc, char const *argv[])
{
    int a =10;

    int *ptr = &a; // 0x01 Dia chi 

    printf("Dia chi a: %p\n", &a);

    printf("Gia tri cua bien ptr: %p\n", ptr);

    return 0;
}
```

### 2. Pointer Hàm 
- Con trỏ trỏ đến một hàm
- Cú pháp:
void (*Tencontro)(<input của con trỏ>)

```cpp
void tong(int a, int b){
    printf("Tong: %d va %d = %d \n", a, b, a+b);
} 

void hieu(int a, int b){
    printf("Hieu: %d va %d = %d \n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}

int main( int argc, char const *argv[]) {

    int (*ptrTich)(int, int) = &tich;

    printf("Tich: %d\n ", ptrTich(5,5));

    return 0;

}
```
#### Pointer Hàm với input là pointer
```cpp
void tong(int a, int b){
    printf("Tong: %d va %d = %d \n", a, b, a+b);
} 

void hieu(int a, int b){
    printf("Hieu: %d va %d = %d \n", a, b, a-b);
}

void tinhToan( int a, int b, void (*ptr)(int a, int b)){
    printf("Ham tinh toan\n");
    ptr(a,b);
}

int main(int argc, char const *argv)
{
    tinhToan(5,6, &tong);

    tinhToan(7,3, &hieu);
    
    return 0;

}
```
#### void pointer
    Lỗi cần tránh khi khai báo con trỏ
- Trong trường hợp sau sẽ bị lỗi khi khai báo con trỏ char mà trỏ đến vị trí int => Khắc phục bằng con trỏ void

```cpp
int main(int argc, char const *argv[])
{
    int a =10;

    char *ptr = &a; 
    return 0;
    // Chương trình báo lỗi
}

```
- Khắc phục sẽ sử dụng con trỏ void.
- Chú ý khai báo kiểu dữ liệu cho con trỏ void => Ép kiểu dữ liệu

```cpp
int main(int argc, char const *argv[])
{
    void *ptr;

    int a =10;
    char *ptr = &a; 


    double b = 10.2;

    char c = 'A';

    char *ptr = &a; 
    return 0;
}

```

## Lesson 3: Memory Allocation

![Ảnh Phân vùng nhớ](https://i0.wp.com/securitydiaries.com/wp-content/uploads/2018/11/memory-segmets.png?w=340&ssl=1)

#### Text :

- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction. 

- Chứa khai báo hằng số trong chương trình (.rodata)

Khi chương trình napjp vào VXL (sử lưu vào bộ nhớ Flask - Tắt đi mở lại vẫn còn lưu lại), Khi sử dụng sẽ Copy chương trình vào phân vùng RAM để chạy ( Do tốc độ chạy trên Ram nhanh hơn tuy nhiên Ram không lưu lại khi tắt máy)

- Chỉ đọc không sử đổi được chương trình 

Ví dụ các biến `const int i = 10;` được lưu ở Phân vùng Text

#### Data:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

– Được giải phóng khi kết thúc chương trình.

Ví dụ: 
    - static toàn cục `static int b = 20;` 

    - static cục bộ

```cpp
void test(){
    static int b = 20;
}
```

#### Bss:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị **khởi tạo bằng không** or **không khởi tạo**.

– Được giải phóng khi kết thúc chương trình.

Lưu ý:
- Giống phân vùng data nhưng không khởi tạo giá trị ban đầu.

- Cho dù sau này biến này có gán giá trị nhưng vẫn ở nguyên trong vùng nhớ này **không chuyển sang vùng data**

Ví dụ: `static int b;`

#### Stack:

– Quyền truy cập là read-write.

– Được sử dụng cấp phát cho biến local, input parameter của hàm,…

– Sẽ được giải phóng khi ra khỏi block code/hàm

```cpp
void tong(int a, int b){
    int c;
    c = a + b;
    printf("Tong a va b: %d\n", c);
    printf(" Dia chi a: %p\n", &a);
    printf(" Dia chi b: %p\n", &b);
    printf(" Dia chi c: %p\n", &c);
}

int main(int argc, char const *argv[])
{   
    tong(6,9);
    // int a = 6; // 0xc1
    // int b = 9; // 0xc5
    // int c;       //0ca3
    printf("-----");
    tong(2,10);

    return 0;

}

```
Sau khi sử dụng địa chỉ cho các biến ở tong(6,9), nó sẽ thu hồi vùng nhớ lại sau khi thực thi chương trình xong; khi mà thực hiện chương trình mới nó sử dụng lại các địa chỉ đó để thực thi chương trình tiếp theo; Do đó khi print các Địa chỉ giữa 2 chương trình khác nhau là như nhau

Output
    Tong a va b: 15
    Dia chi a: 00000000005ffe80
    Dia chi b: 00000000005ffe88
    Dia chi c: 00000000005ffe6c
    -----
    Tong a va b: 12
    Dia chi a: 00000000005ffe80
    Dia chi b: 00000000005ffe88
    Dia chi c: 00000000005ffe6c


#### Heap:
    – Quyền truy cập là read-write.

    – Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

    – Sẽ được giải phóng khi gọi hàm free,…

```cpp
#include <stdint.h>

int main(){
    
    uint32_t *ptr = array;

    for (int  i = 0; i<5; i++){
        
        printf("Dia chi: %p\n", ptr+i);

        printf("Gia tri: %d\n", *(ptr+i));

    }
    
    return 0;
}
```

```cpp
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
```


## Lesson 4: Variable

### Biến Static
```cpp
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
}s

// Output
// i = 0, x = 0
// i = 1, x = 0
// i = 2, x = 0
```
### Biến Extern

VD: Muốn gọi biến a ở file test. sang file main.c, ta thực hiện ở file main.c như sau:
```cpp
extern a;
```


Tại Terminal gõ: gcc main.c test.c --> enter Gõ ./main

- Khi dùng extern không lấy được đc biến từ static vì biến này chỉ tồn tại trong file đó thôi
- Ứng dụng của static toàn cục cho thiết kế thư viện, user chỉ quan tâm input và output và không để người dùng can thiệp vào quá trình xử lý tính toán của chương trình

```cpp
void input 

```


## Lesson 5: Compiler

- Quá trình của một chương trình:
    * Source file: main.c (.c/.h/.cpp/.)
    * Preprocessor: Tiền xử lý -> Tạo ra file Preprocessed Source (main.i)
        
        cú pháp `gcc -E main.c -o main.i`
    * Compiler => Tạo ra file Assembly code (main.s)
        
        Cú pháp `gcc  main.i -o main.s`
    * Assembler => Object File main.o (chương trình này hỗ trợ mã Hex và BIN)
    * Linker => Tạo file cuối executable (với Window tạo .exe/ vi điều khiển thì tạo .hex hoặc .bin)

![Compiler Process](./Image/Compiler.png)


## Lesson 6: MACRO

### ifndef 
`#ifndef SIZE` Nếu có LABEL nào được định nghĩa chưa, Nếu nó định nghĩa rồi thì không sử dụng nội dung trong này
- Chỉ xảy ra ở quá trình tiền xử lý 
- Ứng dụng xây dựng thư viên để định nghĩa các Label và khi chạy lại không định nghĩa nữa

```cpp
// #define SIZE 20

#ifndef SIZE
// Nội dung trong này không sử dụng

int var = 20;

#endif

int main(int argc, char const *argv[])
{

    return 0;
}
```

<details><summary>Cách người ta quy chuẩn đặt tên </summary>
<p>

__STM8S_IT_H
Tên file_Interupt_Header

</p>
</details>

### Macro xây dựng thư viện
- Ứng dụng chương trình Macro vào build thư viện
- Quá trình này xảy ra ở Tiền xử lý chưa đi vào chương trình
Chương trình thư viện  "lib.c"
```cpp

#define STM32F103 0
#define ATMEGA 1
#define PIC16F887 2

// Các thanh ghi ở đây mang tính ví dụ (ALU, AIT)

#if MCU == STM32F103

void Blinkled(){
    DRC = !DRC;
    delay(1000);
}

#elif MCU == ATMEGA

void Blinkled(){
    ALU = !ALU;
    delay(1000);
}

#elif MCU == PIC16F887

void Blinkled(){
    AIT = !AIT;
    delay(1000);
}

#endif

```

Chương trình chính main.c, #include lib.c vào
```cpp
#include <stdio.h>
#define MCU PIC16F887 // THAY ĐỔI MACRO Ở ĐÂY CHƯƠNG TRÌNH SẼ BUILD THEO THƯ VIỆN IF ELSE
#include "lib.c"


int main(int argc, char const *argv[])
{
    while (1)
    {
        /* code */
        Blinkled();
    }
        
    return 0;
}
```


### Macro function

```cpp
#define SUM(a,b) a+b

int main(int argc, char const *argv[])
{
    printf("Tong a va b:  %d\n", SUM(5,6));

    printf("Tong a va b:  %d\n", SUM(1,7));

    printf("Tong a va b:  %d\n", SUM(8,2));

    return 0;

}
```
#### Multiline Macro

- Sử dụng macro multiline như một function
- Yêu cầu có dâu “\” cuối mỗi hàng; Ngoại trừ dòng cuối cùng để khai báo macro funtion
```cpp
#include<stdio.h>

#define CREATE_FUNC(name, cmd)  \
void name(){                    \
    printf("%s", (char*)#cmd);  \
}

// Thêm dấu "#" trước label để hiểu là chuỗi 

CREATE_FUNC(test, This is test 1\n);

CREATE_FUNC(test2, This is test 2\n);

int main(int argc, char const *argv[])
{
    test();

    test2();
    
    return 0;

}

```

Ví dụ khác
```cpp
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
```


`#define VAR(...) __VA_ARGS__`
- The __VA_ARGS__ refers back again to the variable arguments in the macro itself.



### Struct & Union
#### Struct
- Kiểu dữ liệu do người dùng tự định nghĩa
```cpp
typedef struct{
    int x;
    int y;
    int z;
} typeData;

int main(int argc, char const *argv[])
{
    // typeData Data = {1,2,3};
    
    typeData Data;
    
    Data.x = 30;

    Data.y = 50;

    Data.z = 2;

    printf("x = %d, y = %d, z = %d \n", Data.x, Data.y, Data.z);

    return 0;
}
```


```cpp
typedef struct{
    uint8_t var; // 8 bit = 1 byte
    uint32_t var2; // 32 bit = 4 byte
} typeData;

int main(int argc, char const *argv[])
{

    printf("size = %d byte\n", sizeof(typeData));   // Kết quả là 8 byte

    return 0;
}
```


```cpp

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
```

#### Union

```cpp

#include <stdio.h>
#include <stdint.h>

typedef union{
    uint8_t var1[5];    
    uint8_t var2[3]; 
    uint8_t var3[2];   
} typeData;            


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

```

## Lesson 8: BITMASK

### Thao tác Bit


</details>



<details> <summary> C++ Programming  </summary> 

## Class


```cpp
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

class sinhvien 
{
    public: // Khai báo các biến riêng của đối tượng đó thôi
        uint8_t ID;
        string NAME;
        uint8_t OLD;

        // sinhvien(uint8_t id, string name, uint8_t old); // Mặc định đã có

        void setNAME(string name){
            NAME = name;
        }
        
};


int main(){

    sinhvien sv; // Tạo một cái đối tượng của class sinhvien; còn sv là một đối tượng

    sv.setNAME("tuan"); // Gán biến cho các đối tượng

    int key = 0;
    cout << sv.NAME;
    return 0;
}
```

Nhập và xuất trong C++
```cpp
int main(){
    cout << "Nhap key: ";

    cin >> key;
    cout << key;
}
```

Cách khai báo class khác
</details>
