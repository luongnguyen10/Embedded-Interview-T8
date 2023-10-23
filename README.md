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
- Ví dụ một class cơ bản
- Hàm trong C = Method
- Biến trong c = Property

### Khai báo class
* Cấu trúc cơ bản của một class như sau
```cpp
using namespace std;
class DoiTuong{
    public: // Phạm vu truy cập
        DoiTuong(){ // Đối tượng đầu tiên được gọi là Conductor không có thông số đầu vào
            DoiTuong::ten = ten;   // Có tham số đầu vào
            DoiTuong::tuoi = tuoi;
        }


        string ten;  // Property
        int tuoi;
        void nhapThongTin(string ten, int tuoi){
            DoiTuong::ten = ten;
            DoiTuong::tuoi = tuoi;
            }
        void hienThi(){ 
            cout<<"Ten: "<<DoiTuong::ten<<endl;
            cout<<"Tuoi: "<<DoiTuong::tuoi<<endl;
        }
};

int main(int argc, char const *argv[]){
    DoiTuong dt; // Object dt thuộc Class Doituong
    
    dt.nhapThongTin("Hoang", 21);
    dt.hienThi();
    return 0;
}
```
### Constructors
#### Constructors Có tham số đầu vào 
- Khai báo Constructors có tham số đầu vào

Khai báo 1 hàm tự động khởi chạy đầu tiên

```cpp
class DoiTuong{
    public:
        DoiTuong(string ten, int tuoi){ 
            DoiTuong::ten = ten;  
            DoiTuong::tuoi = tuoi;
        }
};

int main(int argc, char const *argv[]){
    DoiTuong dt(); 
    return 0;
}

```
#### Constructors Không có tham số đầu vào 
- Khai báo Constructors có tham số đầu vào

Khai báo 1 hàm tự động khởi chạy đầu tiên

```cpp
class DoiTuong{
    public:
        DoiTuong(){ 
            DoiTuong::ten = ten;  
            DoiTuong::tuoi = tuoi;
        }
};

int main(int argc, char const *argv[]){
    DoiTuong dt(); 
    return 0;
}

```
### Static
Static member (thành viên tĩnh) trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function

* Đối với function, sau khi thực hiện xong khối lệnh và thoát thì static variable vẫn sẽ không mất đi
* Đối với class, static member sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static

- Khi khai báo một C

```cpp
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


## Template

- Template có tính chất đa hình, Vd; viết 1 hàm sài kiểu Template
* Thay vì phải viết lặp lại như thế này:

```cpp
using namespace std;

int sum1 (int a, int b){
    return a + b;
}

double sum2 (double a, double b){
    return a + b;
}

int main(){

    cout << sum1(4,5) << endl;
    cout << sum2(3.5 , 2.2) << endl;
    
    return 0;
}
```

* Thì sẽ viết lại theo template như sau:
```cpp
template <typename datatype>
datatype sum(datatype a, datatype b){
    return a + b;
}

int main(){

    cout << sum(4,5) << endl;
    cout << sum(3.5 , 2.2) << endl;
    
    return 0;
}

```

```cpp
9
5.7

```
* Lưu ý:
- Khi khai báo bao nhiêu typename thì lúc thì cần khai báo đủ các datatype truyền vào hàm



`Namespace` là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

Khi tạo `namespace` nếu muốn dùng chung tên biến của các member thì khi khai báo tên của `namespace` thì phải khai báo tên khác nhau

Nếu dùng chung tên của `namespace` thì tên của các member phải khác nhau (dù có chung file hay khác file), Do khai báo cùng tên `namespace` thì dùng chung bộ nhớ nên nếu tên các member cũng giống thì những member giống nhau sẽ cùng chung 1 địa thì sẽ dẫn đến xung đột vùng nhớ

```c
namespace conOngA{
    int A = 10;
}
namspace conOngB{
    int A = 20;
}
```
Khai báo Constructors
```cpp
    int x, y;
    Position(int x = 0,int y =0): x(x), y(y){}

```
Tương tự
```cpp   
Position(int x = 0,int y =0){
    Position::x = x;
    Position::y = y;
}
```



## 2.OOP
Có 4 đặc tính: Tính kế thừa, đa hình, trừa tượng và đóng gói

**2.1 Inheritance (Tính kế thừa )**
Trong lập trình hướng đối tượng có ý nghĩa, một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó. Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong C++


**2.2 Abstraction (Tính trừu tượng)**
Tính trừu tượng trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class. Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm.

**2.3 Polymorphism (Tính đa hình)**
Tính đa hình trong lập trình hướng đối tượng là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
 
Ví dụ đơn giản, cùng là một class quản lý dữ liệu là các con vật, thì hành động sủa hay kêu của chúng được định nghĩa trong class sẽ cho ra kết quả khác nhau, ví dụ nếu là con mèo thì kêu meo meo, còn con chó thì sủa gâu gâu chẳng hạn. 

```cpp
//Tính đa hình
using namespace std;

class Toanhoc{
    public:
        void tong(int a, int b){
            cout<<"tong a va b: "<<a+b<<endl;
        }
        void tong(int a, int b, int c){
            cout<<"tong a, b va c: "<<a+b+c<<endl;
        }
    
        int tong(int a, double b){
            return a+(int)b;//ép kiểu
        }
};
//C++ có thể tạo ra 2 hàm trùng tên chỉ cần khác input parameter
int main(int argc, char const *argv[])
{
    Toanhoc th;
    th.tong(8,3);

    th.tong(7, 3, 5);
    cout<<"Tong a va b: "<<th.tong(8, 12.5)<<endl;
    
    return 0;
}
```

**2.4 Encapsulation (Tính đóng gói)**
Tính đóng gói trong lập trình hướng đối tượng có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

- Trong quá trình truy cập vào object không được truy cập trực tiếp mà phải thông qua method

## Virtual function
Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất 
khi kế thừa cần phải định nghĩa lại.

Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định 
nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có 
kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.

Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ 
trợ bởi nguồn ngữ C++.

- Virtual Function là khi một hàm được khai báo Virtual thì ở class con kế thừa khi gọi hàm Virtual thì nó sẽ load lại giá trị mới nhất tại class con gọi là Overload.
- Khi object là một class con và trỏ đến method của class cha, trong method class cha sẽ gọi những method khác. Những method đó nếu là kiểu Virtual function thì lúc đó nó sẽ lấy những function cùng cái tên đó mà được định nghĩa lại từ class con.

Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, 
nhưng ngược lại thì không được.

Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử 
dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần 
của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.

```cpp
class Toanhoc{
    public:
        virtual char *txt(){
            return (char*)"Hello world\n";
        }

        void display(){
            printf('%s', txt());
        }

}

class test: public Toanhoc{
    public:
       char *txt(){ // Overide
            return (char*)"Hello world\n";
        }
}

int main(){
    Test th;

    th.display(); // Overload

    return 0;
}
```

## Vector
Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối 
tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp 
trong vector.

Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, 
nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình

Modifiers
1. push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của 
đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.
ten-vector.push_back(ten-cua-phan-tu);
2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các 
giá trị cũ.
ten-vector.assign(int size, int value);
3. pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một 
vector.
4. insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ 
bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử 
được chèn vào trước vị trí được trỏ.
5. erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
6. emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
7. emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa 
vector, phần tử mới sẽ được thêm vào cuối vector
8. swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một 
vector khác cùng kiểu. Kích thước có thể khác nhau.
9. clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector

10. size(): trả về kích thước vector
11. empty(): Kiểm tra vector có rỗng không



bản chất vector là class một thư viện cung cấp các method, sử dụng malloc, calloc để cấp phát động

```cpp
#include vector

int main(){

    vector<int>array = {1,2,3,4,5,6};
    for (int i =0; i< array.size(); i++){
        printf("%d\n ", array[i]);
    }
}
```


## C++ Advance

### Smart pointer

- Cấp phát bộ nhớ động trong C++
- Tuy nhiên khi muốn thu hồi vùng nhớ cần Delete nó đi
```cpp

int main(){
    
    int *ptr = new int; // Từ khoá new để cấp phát động

    *ptr = 20;

    cout << "ptr: "<< *ptr<< endl;

    int *array = new int [10];
    
    for ( int i = 0; i < 10; i++){

        array[i] = 2*i;

    }

    for ( int i = 0; i < 10; i++){
        cout<<"i: " << i<< endl;

    }
    
```


- Smart pointer

Lưu trong phân vùng nhớ Heap, Sau khi thực hiện xong chương trình sẽ tự động thu hồi vùng nhớ

Tạo cấp phát động

* Có 2 loại 
- unique_ptr: Duy nhất một con trỏ vào địa chỉ
- shared_ptr: Nhiều con trỏ vào 1 địa chỉ


### Threads

Thêm thư viện
```cpp
#include <thread>

```


```cpp
#include <thread>
#include <chrono>

void task1(){
    int i =0;
    while(1){
        this_thread::sleep_for(chrono::seconds(1)); // làm chương trình delay 1s
        cout<<"i = "<< i++ <<endl;
    }
    
}

int main(){
    task1();
}

```


</details>
