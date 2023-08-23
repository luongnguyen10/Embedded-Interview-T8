#include <stdio.h>
#include <stdint.h>
#include <time.h>

void delay(){
    for (int i = 0; i < 10000000; i++);
}

int main(int argc, char const *argv[])
{
    clock_t start, end;

    double time;

    register i = 0; // Thêm register vào int

    start = clock();

    for (; i < 100000000; i++);
    
    end = clock();
    
    time = (double)(end -start)/CLOCKS_PER_SEC;

    printf("time: %f\n", time);
    
    return 0;
}

// Kết quả Không Register có time: 0.167000
// Kết quả với có Register time: 0.034000
// Kết quả tốc độ nhanh chậm dựa trên tốc độ đọc ghi giữa ram với register của từng máy
// 