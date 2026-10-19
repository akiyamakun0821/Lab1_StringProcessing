#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char str[100];
    int length;
    int i;
    int start;
    int count;
    int shift;
    int j;

    printf("Введите строку (Array approach): ");

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

    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            start = i;
            count = 0;

            while (str[i] == '.') {
                count++;
                i++;
            }

            if (start > 0 && isalpha((unsigned char)str[start - 1]) && (count % 2 != 0)) {
                if (count > 1) {
                    shift = count - 1;
                    j = start + 1;

                    while (true) {
                        str[j] = str[j + shift];
                        if (str[j] == '\0') break;
                        j++;
                    }
                }
                i = start + 1;
            }
        }
        else {
            i++;
        }
    }

    printf("Результат: %s\n", str);
    return 0;
}
