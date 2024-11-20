#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    char * merged_word = malloc(sizeof(char)*(strlen(word1) + strlen(word2) + 1));
    char * tmp = merged_word;

    while (*word1 != '\0' || *word2 != '\0') {
        if (*word1 != '\0') *tmp++ = *word1++;
        if (*word2 != '\0') *tmp++ = *word2++;
    }

    *tmp = '\0';
    return merged_word;
}

int main() {
    char word1[] = "abc";
    char word2[] = "pqr";

    // Call the function
    char *merged = mergeAlternately(word1, word2);

    // Print the result
    printf("Merged string: %s\n", merged);

    // Free the allocated memory
    free(merged);
}