#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG = 0; // 1 byte 00000000

typedef enum {
    AO = 1 << 0,
    QUAN = 1 << 1,
    VAY = 1 << 2,
    DAM = 1 << 3,
    NHAN = 1 << 4,
    VONG_TAY = 1 << 5,
    GIAY = 1 << 6,
    TUI = 1 << 7,
} DO_DUNG_CA_NHAN;

void ADD_Vao_gio_hang(uint8_t *gio_hang, DO_DUNG_CA_NHAN ten_do_dung) {
    *gio_hang |= ten_do_dung;
}

void Check_item(uint8_t *gio_hang, DO_DUNG_CA_NHAN items_to_check) {

    if ((*gio_hang & items_to_check) == items_to_check) {
        printf("All items are in the cart.\n");
        
    } else {
        printf("Some items are missing from the cart.\n");
        DO_DUNG_CA_NHAN missing_items = items_to_check & ~(*gio_hang);
        printf("Missing items: ");
        
        // Iterate through the missing items and print their names
        for (DO_DUNG_CA_NHAN item = 1; item <= TUI; item <<= 1) {
            if (missing_items & item) {
                switch (item) {
                    case AO:
                        printf("AO ");
                        break;
                    case QUAN:
                        printf("QUAN ");
                        break;
                    case VAY:
                        printf("VAY ");
                        break;
                    case DAM:
                        printf("DAM ");
                        break;
                    case NHAN:
                        printf("NHAN ");
                        break;
                    case VONG_TAY:
                        printf("VONG_TAY ");
                        break;
                    case GIAY:
                        printf("GIAY ");
                        break;
                    case TUI:
                        printf("TUI ");
                        break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    ADD_Vao_gio_hang(&GIO_HANG, TUI | NHAN | VONG_TAY | VAY | DAM);

    Check_item(&GIO_HANG, NHAN | AO | DAM);

    return 0;
}
