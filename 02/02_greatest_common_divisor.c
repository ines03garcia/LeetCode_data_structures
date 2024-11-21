#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDivisor(char* str, char* div) {
    int i, j = 0;
    int str_len = strlen(str);

    if (strlen(div) > str_len) return 0;
    
    for (i = 0; i < str_len; i++) {
        if (div[j] == '\0') j = 0;

        if (str[i] != div[j]) {
            return 0;
        }

        j++;
    }

    if (div[j] == '\0') return 1;

    return 0;
}

char* gcdOfStrings(char* str1, char* str2) {
    int i = 0, j = 1;

    char* div = malloc(sizeof(char) * (strlen(str1) + 1));
    char* greatest = malloc(sizeof(char) * (strlen(str1) + 1));
    greatest[0] = '\0';

    while (str1[i] != '\0') {
        div[i] = str1[i];
        div[j] = '\0';

        if (isDivisor(str1, div) && isDivisor(str2, div)) {
            strcpy(greatest, div);
        }

        i++;
        j++;

    }
     
    return greatest;
}

int main() {
    char word1[] = "ABABAB";
    char word2[] = "ABAB";


    // Call the function
    char *divisor = gcdOfStrings(word1, word2);

    // Print the result
    printf("Greatest Divisor: %s\n", divisor);

    // Free the allocated memory
    free(divisor);
}