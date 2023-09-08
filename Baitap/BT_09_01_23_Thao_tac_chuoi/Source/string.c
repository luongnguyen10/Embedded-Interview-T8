#include "string.h"

int takeSize(char array[]){
    int i = 0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}

void findBlank(char array[]){
    int i = 0 ;
    int size = takeSize(array); 

    int space_positions[size]; //    Assuming a maximum of 100 spaces
    int space_count = 0; //         Count the number of spaces

    while (array[i] != '\0'){
        if (array[i] == ' ') {
            space_positions[space_count] = i;
            space_count++;
        }
        i++;
    }
    
    char newArray[size];
    
    for (int i = 0; i < size; )
    {   
        int count = 0;
        for (int j = space_count; j >0; j--)

            newArray[i] = space_positions[j];
            count++;
        i+=count;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%c", newArray[i]);
    }
}

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str) {
    int length = takeSize(str);

    // Reverse the whole string 
    reverse(str, str + length - 1);

    // Reverse each word in the new string 
    char *word_start = str;
    for (char *p = str; *p; p++) {
        if (*p == ' ') {
            reverse(word_start, p - 1);
            word_start = p + 1;
        }
    }
    // Reverse the last word
    reverse(word_start, str + length - 1);
}
