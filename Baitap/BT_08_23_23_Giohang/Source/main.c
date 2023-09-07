#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG = 0; // 1 byte 00000000

typedef enum{
    AO          = 1 << 0,   // 0000 0001
    QUAN        = 1 << 1,   // 
    VAY         = 1 << 2,
    DAM         = 1 << 3,
    NHAN        = 1 << 4,
    VONG_TAY    = 1 << 5,
    GIAY        = 1 << 6,
    TUI         = 1 << 7,
}DO_DUNG_CA_NHAN;

const char* itemLabels[] = {
    "AO",
    "QUAN",
    "VAY",
    "DAM",
    "NHAN",
    "VONG_TAY",
    "GIAY",
    "TUI"
};

void ADD_Vao_gio_hang(uint8_t *gio_hang, DO_DUNG_CA_NHAN ten_do_dung){
    *gio_hang |= ten_do_dung;
}

void Delete_Item(uint8_t *gio_hang, DO_DUNG_CA_NHAN ten_do_dung){
    *gio_hang &= ~ten_do_dung;
}

void CheckItem(uint8_t *gio_hang, DO_DUNG_CA_NHAN item)
{
    printf("Kiem tra Gio hang: \n");

    for(int i = 0 ; i < 8 ; i++)
    {
        uint8_t temp = 1 << i;
        if(temp & item)
        {
            printf(" - %s ",itemLabels[i]);
            if( *gio_hang & temp)   {
                printf("da co.\n");
            }
                
            else printf("chua co.\n");
        }
    }
}



int Check_item_1(uint8_t gio_hang, DO_DUNG_CA_NHAN item) {
    return gio_hang & item;
}

void Show_item(uint8_t *gio_hang) {

    printf("Danh sach san pham duoc chon:\n");

    for(int i = 0 ; i < 8 ; i++)
    {
        uint8_t temp = 1 << i;
        if(*gio_hang & temp)
        {   
            printf(" - %s \n",itemLabels[i]);
        }
    }
}


int main(){
    
    ADD_Vao_gio_hang(&GIO_HANG, AO | TUI | NHAN | VONG_TAY);

    Delete_Item(&GIO_HANG, NHAN);

    CheckItem(&GIO_HANG, NHAN|VONG_TAY);

    Show_item(&GIO_HANG);

    return 0;
}
