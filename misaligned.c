#include <stdio.h>
#include <assert.h>
#include <string.h>

#define COLOR_PAIR_COUNT  25

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorPair
{
    int  pairNumber;
    char MajorColorName[15];
    char MinorColorName[15];
};

struct ColorPair colorPairInfo[COLOR_PAIR_COUNT];

void printToConsole(struct ColorPair* colorPairPtr, int pairIndex)
{
	printf("%d | %s | %s\n", colorPairPtr[pairIndex].pairNumber, colorPairPtr[pairIndex].MajorColorName, colorPairPtr[pairIndex].MinorColorName);
}

int printColorMap(struct ColorPair* colorPairInfoPtr) {

    int i = 0, j = 0, pairNumberIndex = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
        	colorPairInfoPtr[pairNumberIndex].pairNumber = (i * 5 + j + 1);
        	strcpy(colorPairInfoPtr[pairNumberIndex].MajorColorName , majorColor[i]);
        	strcpy(colorPairInfoPtr[pairNumberIndex].MinorColorName , minorColor[j]);
            printToConsole(colorPairInfoPtr, pairNumberIndex);

            pairNumberIndex++;
        }
    }
    return i * j;
}

void testColorMap(struct ColorPair* testcolorPairInfoPtr)
{
	int i = 0, j = 0, pairNumberIndex = 0;
	for(i = 0; i < 5; i++) {
	    for(j = 0; j < 5; j++) {
	        assert(testcolorPairInfoPtr[pairNumberIndex].pairNumber == (i * 5 + j + 1));
	        assert(!(strcmp(testcolorPairInfoPtr[pairNumberIndex].MajorColorName , majorColor[i])));
	        assert(!(strcmp(testcolorPairInfoPtr[pairNumberIndex].MinorColorName , minorColor[j])));

	        pairNumberIndex++;
	     }
         }
}

int main() {
    int result = printColorMap(colorPairInfo);
    assert(result == 25);
    testColorMap(colorPairInfo);
    printf("All is well (maybe!)\n");
    return 0;
}
