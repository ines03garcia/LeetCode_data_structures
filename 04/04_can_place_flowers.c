#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    bool prev, curr, next;

    if (flowerbedSize == 1) {
        curr = flowerbed[0];

        if (!curr) return (n <= 1);
        return (n == 0);
    }

    for (int i = 0; i < flowerbedSize; i++) {
        if (i == 0) {
            curr = flowerbed[i];
            next = flowerbed[i+1];

            if (!curr && !next) {
                flowerbed[i] = 1;
                n--;
            }
        } else if (i == flowerbedSize - 1) {
            prev = flowerbed[i-1];
            curr = flowerbed[i];

            if (!curr && !prev) n--;
        } 
        else {
            prev = flowerbed[i-1];
            curr = flowerbed[i];
            next = flowerbed[i+1];

            if (!prev && !curr && !next) {
                flowerbed[i] = 1;
                n--;
            } 
        }
    }

    return (n <= 0);
}


int main() {
    int flowerbed[] = {1,0,0,0,1};
    int flowerbedSize = 5;
    int n = 2;

    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);
    
    printf("%d\n", result);

    return 0;
}