enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

int testPairToNumber(enum MajorColor major,
                    enum MinorColor minor,
                    int expectedPairNumber)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if((majorColor[i] == major) &&
            		(minorColor[j] == minor) &&
					((i * 5 + j) == expectedPairNumber))
            {
            	// color pair match is found
            	return 1;
            }
            else
            {
            	// no color pair match found
            	return 0;
            }
        }
    }
}
