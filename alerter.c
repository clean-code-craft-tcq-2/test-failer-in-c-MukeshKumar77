#include <stdio.h>
#include <assert.h>

#define OK_TEMPERATURE		    200
#define NOT_OK_TEMPERATURE  	500

int alertFailureCount = 0;

int networkAlertStub(float celcius)
{
    int returnVal;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius > 200)
    {
        returnVal =  NOT_OK_TEMPERATURE;
    }
    else
    {
    	returnVal =  OK_TEMPERATURE;
    }
    return returnVal;
}

int networkAlert(float celcius)
{
    int returnVal;
    if(celcius > 200)
    {
        returnVal =  NOT_OK_TEMPERATURE;
    }
    else
    {
    	returnVal =  OK_TEMPERATURE;
    }
    return returnVal;
}

float convertFarenheitToCelcius(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, int (*fnPtrForNetworkAlert)(float))
{
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = fnPtrForNetworkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

void testThresholdOfTemperature(void){
    int (*fnPtrForNetworkAlert)(float) = networkAlertStub;
    alertInCelcius(400.5, fnPtrForNetworkAlert);
    alertInCelcius(303.6, fnPtrForNetworkAlert);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
}

int main()
{
    testThresholdOfTemperature();
    return 0;
}
