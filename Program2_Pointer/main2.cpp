#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int length;
    char* readPtr;
    char* writePtr;
    char prevChar;
    int count;
    int i;

    printf("Введите строку (C-style / Pointer approach): ");

    if (fgets(str, sizeof(str), stdin) != NULL) {
        length = 0;
        while (str[length] != '\0') {
            if (str[length] == '\n') {
                str[length] = '\0';
                break;
            }
            length++;
        }
    }

    readPtr = str;
    writePtr = str;
    prevChar = '\0';

    while (*readPtr != '\0') {
        if (*readPtr == '.') {
            count = 0;

            while (*readPtr == '.') {
                count++;
                readPtr++;
            }

            if (isalpha((unsigned char)prevChar) && (count % 2 != 0)) {
                *writePtr = '.';
                writePtr++;
                prevChar = '.';
            }
            else {
                for (i = 0; i < count; i++) {
                    *writePtr = '.';
                    writePtr++;
                }
                prevChar = '.';
            }
        }
        else {
            prevChar = *readPtr;
            *writePtr = *readPtr;
            writePtr++;
            readPtr++;
        }
    }
    *writePtr = '\0';

    printf("Результат: %s\n", str);
    return 0;
}
