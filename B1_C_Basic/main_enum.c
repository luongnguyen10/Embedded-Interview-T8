#include <stdio.h>
#include <stdint.h>

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
