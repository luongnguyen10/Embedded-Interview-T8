#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char *arr;
    uint8_t length;
} Words;

int words_equal(const Words *word1, const Words *word2) {
    if (word1->length != word2->length) {
        return 0; // Lengths are different, arrays can't be equal
    }

    for (uint8_t i = 0; i < word1->length; i++) {
        if (word1->arr[i] != word2->arr[i]) {
            return 0; // Characters are different, arrays can't be equal
        }
    }

    return 1; // Arrays are equal
}

void copy_substring(char *dest, const char *src, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

int main() {
    char input[] = " mot hai ba, bon, ba, hai mot, bon hai ba";
    Words substrings[100];
    int counts[100] = {0};
    int numSubstrings = 0;
    
    char *token = input;
    char delimiter = ' ';

    while (*token != '\0') {
        while (*token == delimiter) {
            token++;
        }

        char *substringStart = token;
        uint8_t len = 0;

        while (*token != '\0' && *token != delimiter) {
            len++;
            token++;
        }

        int found = 0;

        for (int i = 0; i < numSubstrings; i++) {
            if (words_equal(&substrings[i], &(Words){.arr = substringStart, .length = len})) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            copy_substring(substrings[numSubstrings].arr, substringStart, len);
            substrings[numSubstrings].length = len;
            counts[numSubstrings]++;
            numSubstrings++;
        }

        printf("Token: '%.*s'\n", len, substringStart);
    }
    
    for (int i = 0; i < numSubstrings; i++) {
        printf("'%.*s' appears %d times\n", substrings[i].length, substrings[i].arr, counts[i]);
    }

    return 0;
}
