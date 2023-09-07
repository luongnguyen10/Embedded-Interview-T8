#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct{
    char *arr;
    uint8_t length;
    uint8_t quantity;
    bool status;
}Words;

int8_t take_size(char array[]){
    // Đọc kích thước chuỗi 
    int i = 0;
    int size = 1 ;
    while (array[i] != '\0'){
        if (array[i] == ' '){
            size++;
        }
        i++;
    }
    printf(" count : %d\n", size);
    return size;
}


Words *string(char array[], uint8_t size){

    int i = 0;
    Words *word = malloc(size * sizeof(Words)); // Tạo mảng
    
    int index = 0;
    word[index].arr = array;

    int count = 0;

    // Lấy kích thước từng sub string
    while (array[i] != '\0')
    {
        if (array[i] == ' ' || array[i] == ','  ){
            word[index].length = count;
            
            word[++index].arr = array+i+1; // tại vị trí " " nên phải là +i+1
            // printf(" count: %d\n", count);
            count = 0;
        }else {
            count++;
        }
        i++; 
    }
    // printf(" count: %d\n", count);
    // count = 0;
    word[index].length = count;
    return word;
}

void display( Words word){
    for (int i = 0; i < word.length; i++)
    {
        printf("%c", word.arr[i]);
    }
    
}

// So sánh 2 mảng
bool isEqual(Words word1, Words word2){
    if (word1.length != word2.length) {
        return false; 
    }
    int counter = 0;
    for (int i = 0; i < word1.length; i++){
        if (word1.arr[i]!= word2.arr[i]){
            counter++;
        }
    }
    if (counter >0){
        return false;
    } else return true;
        
}


void findname(Words array[], uint8_t size){
    for ( uint8_t i = 0; i < size; i++){
        uint8_t count = 0;
        for (uint8_t j = 0; j < size; j++ ){
            int8_t i_ptr = 0;

            while ( array[i].arr[i_ptr] == array[j].arr[i_ptr])
            {
                /* code */
                i_ptr++;
                
                if (array[i].length == i_ptr){
                    count++;
                    if (count >=2) array[j].status = false;
                    else array[i].status = true;
                    break;
                }
            }
            i_ptr -0;
        }
        array[i].quantity = count;
        
    }
    printf("Done!!\n");
}

void show_result(Words array[], uint8_t size){
    for ( uint8_t i = 0; i < size; i++){
        if ( (array[i].status == true) & (array[i].length > 0)) {
            display(array[i]);
            printf(" appears %d times\n ", array[i].quantity);
        }
    }
}


int main(){

    char input[] = "hai mot hai ba, bon nam, hai hai, ba mot, ba";

    uint8_t size = take_size(input);

    Words *word = string(input, size);

    findname(word, size);

    show_result(word, size);

    return 0;
    
    // Draft
    
    // for (int i = 0; i < 13; i++)
    // {   
    //     // if (isEqual(word[i], word[i]))
    //     display(word[i]);
    //     printf(" \n");
    // }
    
    // if (isEqual(word[0], word[2]) == true) {
    //     printf("The arrays are the same.\n");
    // } else {
    //     printf("The arrays are different.\n");
    // }
    
    // for (int i = 0; i < numSubstrings; i++) {
    //     printf("'%.*s' appears %d times\n", word[i].length, word[i].arr, counts[i]);
    // }

    
}
