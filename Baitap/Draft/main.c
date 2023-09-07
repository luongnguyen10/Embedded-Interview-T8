#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_chars;  // Number of characters the user wants to allocate space for
    char *buffer;   // Pointer to the allocated memory

    printf("Enter the number of characters: ");
    scanf("%d", &num_chars);

    // Allocate memory for the characters
    buffer = (char *)malloc(num_chars * sizeof(char));

    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return with an error code
    }

    printf("Memory allocated for %d characters.\n", num_chars);

    // Remember to free the allocated memory when you're done using it
    free(buffer);

    return 0;
}





