#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *result = malloc(sizeof(bool) * candiesSize);
    int max = candies[0];

    *returnSize = candiesSize;

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max) max = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max) result[i] = true;
        else result[i] = false;
    }
    
    return result;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = 5;
    int extraCandies = 3;
    int *returnSize = malloc(sizeof(int));

    bool *result = kidsWithCandies(candies, candiesSize, extraCandies, returnSize);
    for (int i = 0; i < candiesSize; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}