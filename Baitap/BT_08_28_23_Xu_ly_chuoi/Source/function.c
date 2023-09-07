#include "myheader.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
* File: function.c
* Author: Nguyen Ba Luong
* Date: 06/09/2023
* Description: File the the day of week from the given date 
*/

/*
* Function: upperCharacterAfterDot
* Description: This function Upper the character after the dot
*                in hoa các kí tự sau sau dấu chấm. = > TODAY WE LEARN ABOUT THAT ...
* Input:
*   array[] - char
* Output:
*   returns The character with UPPER after the dot
*/


void upperCharacterAfterDot(char array[]){
    int8_t i = 0 ;
    uint8_t flat = 0;

    printf("\nIn ra chuoi IN HOA sau dau cham '.'\n ");

    while (array[i] != '\0'){
        if (array[i] == '.'){
            flat++;
        }
        if (flat > 0){
            if (array[i]>=97 && array[i]<=122) array[i]-=32;
        }
        printf("%c", array[i]);
        i++;
    }
    printf("\n");
}

/*
* Function: takeLength
* Description: Calculate the length of character array
* Input:
*   array[] - char
* Output:
*   returns int length of array
*/

uint8_t takeLength(char array[]){
    int i = 0;
    for ( i = 0; array[i] != '\0'; ++i);
    return i;
}

/*
* Function: findText
* Description: Calculate the length of character array
* "how to do", => in ra có hoặc không, nếu có thì in ra vị trí
* Input:
*       array[] - string 
*       str[] - the text need to find
* Output:
*       print yes or no the the text in string; if yes print the position
*/

uint8_t findText(char array[],char str[]){
    printf("\nTim kiem chuoi trong chuoi\n");
    uint8_t i = 0;
    uint8_t size = takeLength(str);
    uint8_t count = 0;

    while (array[i] != '\0'){
        uint8_t j = 0 ;
        uint8_t k = i ;
        uint8_t flat = 0;
        while (str[j] != '\0'){
            if (array[k] == str[j])  flat++;
            if (flat == size) {
                count++;
                // printf("Vi tri: %d\n",j );
            }
            k++;
            j++; 
        }
    i++;    
    }
    if (count > 0) printf("Co chuoi trong chuoi\n");
    else printf("Khong co chuoi trong chuoi");
    return count;
    // return 0;
}

/*
* Function: replaceString
* Description: Calculate the length of character array
* // "around the world " => thay thế thành hello, kiểm tra chuỗi, nếu có thì in ra còn không thì in ra không có
* Input:
*       array[] - string 
*       str[] - the text need to find
*       replace_str[] - the text after replace
* Output:
*       print the string after replace the text
*/

void replaceString(char array[],char str[], char replace_str[]){
    
    printf("\nThay the gia tri trong chuoi\n");
    
    uint8_t i = 0;
    // uint8_t count = FindText(array, str);

    // Tính độ dài chuỗi
    uint8_t size_str = takeLength(str);
    uint8_t size_replace_str = takeLength(replace_str);
    uint8_t size_array = takeLength(array);

    uint8_t count = 0;

    // Lấy vị trí đầu và cuối 
    uint8_t first_location;
    uint8_t final_location;

    while (array[i] != '\0'){
        uint8_t j = 0 ;
        uint8_t k = i ;
        uint8_t flat = 0;
        while (str[j] != '\0'){
            if (array[k] == str[j])  flat++;
            if (flat == size_str) {
                count++;
                first_location = i;
                final_location = k;
                printf("Vi tri dau: %d, vi tri cuoi %d\n",first_location,final_location );
            }
            k++;
            j++; 
        }
    i++;    
    }
    
    // Copy ra một mảng mới
    
    uint8_t length_updated = (size_replace_str-size_str) * count + size_array;
    char *new_string = (char *)malloc(((size_replace_str-size_str)*count + size_array )* sizeof(char));
    
    i = 0;
    uint8_t j = 0 ;
    printf("Count: %d, Do dai chuoi moi: %d\n",count, length_updated );
    while (array[i] != '\0'){
        uint8_t k = 0 ;
        if (i == first_location){
            while (replace_str[k] != '\0')
            {
                new_string[j]= replace_str[k];
                k++;
                j++;
            }
            i = i + (final_location - first_location) +1;
        }
        new_string[j]= array[i];
        j++;
        i++;
        }
    
    for (i=0; i < length_updated ; i++)
    {
        printf("%c", new_string[i]);
    }
}
