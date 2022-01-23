const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int testColorPairStub()
{
	int correctColorCoding;
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if((majorColor[i] == MajorColorNames[i]) &&
            		(minorColor[j] == MinorColorNames[j]))
            {
            	// color pair match is found
            	correctColorCoding = 1;
            }
            else
            {
            	// no color pair match found
            	correctColorCoding = 0;
            }
        }
    }
    return correctColorCoding;
}
