#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* inputFile;
    FILE* outputFile;
    char str[100];
    int length;
    char* readPtr;
    char* writePtr;
    char prevChar;
    int count;
    int i;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Ошибка открытия файлов!\n");
        if (inputFile) fclose(inputFile);
        if (outputFile) fclose(outputFile);
        return 1;
    }

    if (fgets(str, sizeof(str), inputFile) != NULL) {
        length = 0;
        while (str[length] != '\0') {
            if (str[length] == '\n') {
                str[length] = '\0';
                break;
            }
            length++;
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

        fputs(str, outputFile);
        printf("Файл успешно обработан. Проверьте output.txt\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
