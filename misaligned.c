#include <stdio.h>
#include <assert.h>
#include "misaligned_test_code.h"

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    int match_found = testPairToNumber(BLACK, ORANGE, 12);
    assert(match_found == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
