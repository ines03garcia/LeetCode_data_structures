#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* reverseVowels(char* s) {
    char* s_vowels = malloc(sizeof(char));
    int nr_vowels = 0;
    int len = strlen(s);
    int i, j = 0;

    for (i = 0; i < len; i++) {
        char c = tolower(s[i]);

        if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            nr_vowels++;
            s_vowels = realloc(s_vowels, sizeof(char) * nr_vowels);
            s_vowels[nr_vowels - 1] = s[i];
        }
    }

    for (i = len - 1; i >= 0; i--) {
        char c = tolower(s[i]);

        if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            s[i] = s_vowels[j];
            j++;
        }
    }

    return s;
}

int main() {
    // MUITO IMPORTANTE, definir char* s   VS   char s[]
    char s[] = "IceCreAm";
    char* result = reverseVowels(s);
    
    printf("%s\n", result);

    return 0;
}