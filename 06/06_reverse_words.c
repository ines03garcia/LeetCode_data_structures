#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* reverseWords(char* s) {
    char* result = malloc(sizeof(char) * (strlen(s) + 1));
    int i = strlen(s) - 1;
    int j = 0, extra_spaces = 0;
    int begining_of_word, end_of_word;

    while (i >= 0) {
        if ((i == strlen(s) - 1) && (s[i] == ' ')) { // trailing spaces

            while (s[i] == ' ') {
                i--;
                extra_spaces++;
            }
        }
        end_of_word = i;

        while ((i >= 0) && (s[i] != ' ')) {
            i--;
        }
        begining_of_word = i + 1;

        while (i < end_of_word) {
            i++;
            result[j] = s[i];
            j++;
        }

        i = begining_of_word - 1;
        while (i >= 0 && s[i] == ' ') {
            if ((i > 0) && (s[i - 1] != ' ')) result[j++] = ' ';
            else extra_spaces++; // leading spaces
            i--;
        }
    }
    
    result[strlen(s) - extra_spaces] = '\0';
    return result;
}

int main() {
    char s[] = "the sky is blue";
    char* result = reverseWords(s);
    
    printf("%s\n", result);

    return 0;
}