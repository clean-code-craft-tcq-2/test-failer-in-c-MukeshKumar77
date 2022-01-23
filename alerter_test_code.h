#define OK_TEMPERATURE		200u;
#define NOT_OK_TEMPERATURE  500u;

int FaliureCountForTemperatureBreach;

int networkAlertStub(float celcius);
int networkAlertStub(float celcius) {
    int tempThreshold;
	printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius >= 0.0 && celcius <= 200.0)
    {
    	tempThreshold = OK_TEMPERATURE;
    }
    else
    {
    	tempThreshold = NOT_OK_TEMPERATURE;
    	FaliureCountForTemperatureBreach++;
    }
    return tempThreshold;
}
