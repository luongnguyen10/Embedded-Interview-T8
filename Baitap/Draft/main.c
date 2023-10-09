#include <stdio.h>
#include <string.h>

// Function to convert a digit to its word representation
const char *digitToWord(int digit) {
    const char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return words[digit];
}

// Function to convert a two-digit number to its word representation
const char *twoDigitToWord(int num) {
    const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (num < 10) {
        return digitToWord(num);
    } else if (num < 20) {
        const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                               "eighteen", "nineteen"};
        return teens[num - 10];
    } else {
        int ten = num / 10;
        int one = num % 10;
        if (one != 0) {
            return strcat(tens[ten], " ") + ones[one];
        } else {
            return tens[ten];
        }
    }
}

// Function to convert a three-digit number to its word representation
const char *threeDigitToWord(int num) {
    int hundred = num / 100;
    int remainder = num % 100;

    if (hundred > 0) {
        if (remainder > 0) {
            return strcat(digitToWord(hundred), " hundred and ") + twoDigitToWord(remainder);
        } else {
            return strcat(digitToWord(hundred), " hundred");
        }
    } else {
        return twoDigitToWord(remainder);
    }
}

int main() {
    char input[100];
    printf("Enter a number in written form: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input by spaces
    char *token = strtok(input, " ");
    int groups[4]; // Array to store the groups of three digits
    int groupCount = 0;

    while (token != NULL) {
        groups[groupCount++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Reverse the order of groups for processing
    for (int i = 0; i < groupCount / 2; i++) {
        int temp = groups[i];
        groups[i] = groups[groupCount - i - 1];
        groups[groupCount - i - 1] = temp;
    }

    // Array to store group names (thousand, million, etc.)
    const char *groupNames[] = {"", "thousand", "million", "billion"};

    // Convert each group of three digits to words
    for (int i = 0; i < groupCount; i++) {
        if (groups[i] != 0) {
            printf("%s %s ", threeDigitToWord(groups[i]), groupNames[i]);
        }
    }

    printf("\n");

    return 0;
}
