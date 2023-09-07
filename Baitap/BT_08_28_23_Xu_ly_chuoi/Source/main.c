#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "myheader.h"

int main()
{
    char input[] = "to help people around the world learn how to do anything. today we learn about that";

    upperCharacterAfterDot(input);

    uint8_t count = findText(input, "how to do");

    replaceString(input, "how to do", "Hellooooooooooooo");

    return 0;
}
