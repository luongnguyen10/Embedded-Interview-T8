#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


// in hoa các kí tự sau sau dấu chấm. = > TODAY WE LEARN ABOUT THAT ...
void UpperCharacterAfterDot(char array[]){
    uint8_t address = 0 ; 
    uint8_t i = 0 ;
    uint8_t flat = 0;

    printf("\nIn ra chuoi IN HOA sau dau cham '.' \n ");

    while (array[i] != '\0'){
        if (array[i] == '.'){
            flat++;
        }
        if (flat > 0){
            if (array[i]>=97 && array[i]<=122)
            array[i]-=32;
        }
        printf("%c", array[i]);
        i++;
    }
    printf("\n ");
}

// "how to do", => in ra có hoặc không, nếu có thì in ra vị trí
uint8_t take_length(char array[]){
    int i = 0;
    for ( i = 0; array[i] != '\0'; ++i);
    return i;
}

uint8_t FindString(char array[],char str[]){
    printf("\nTim kiem chuoi trong chuoi\n");
    uint8_t i = 0;
    uint8_t size = take_length(str);
    uint8_t count = 0;

    while (array[i] != '\0'){
        uint8_t j = 0 ;
        uint8_t k = i ;
        uint8_t flat = 0;
        while (str[j] != '\0'){
            if (array[k] == str[j])  flat++;
            if (flat == size) count++;
            k++;
            j++; 
        }
    i++;    
    }
    if (count > 0) printf("Co chuoi trong chuoi\n");
    else printf("Khong co chuoi trong chuoi");
    return count;
}

// "around the world " => thay thế thành hello, kiểm tra chuỗi, nếu có thì in ra còn không thì in ra không có
void ReplaceString(char array[],char str[], char replace_str[]){
    
    printf("\nThay the gia tri trong chuoi\n");
    uint8_t i = 0;

    uint8_t size_str = take_length(str);
    uint8_t size_replace_str = take_length(replace_str);

    uint8_t count = FindString(array, str);

    char string_replaced[] = malloc((sizeof(size_replace_str)-sizeof(size_str))* count + sizeof(array));
    
    while (array[i] != '\0'){
        uint8_t j = 0 ;
        uint8_t k = i ;
        uint8_t flat = 0;
        uint8_t counter = 0;

        while (array[i] != '\0'){
            uint8_t j = 0 ;
            uint8_t k = i ;
            uint8_t flat = 0;

            while (str[j] != '\0'){
                if (array[k] == str[j])  flat++;
                if (flat == size_str) {
                    counter++;
                    i += size_str;
                }
                k++;
                j++; 
            }  
        string_replaced[i]= array[i];
        i++;
        }
    }
}


int main(){

    char input[] = "to help people around the world learn how to do anything. today we learn about that";

    UpperCharacterAfterDot(input);

    char str[] = "how to do";

    uint8_t count = FindString(input, str);


    char str_replace[] = "Hello";

    ReplaceString(input, str, str_replace);

    return 0;
}
