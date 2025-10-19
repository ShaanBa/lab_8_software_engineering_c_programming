#include <stdio.h>
#include <ctype.h>

double toCelsius(double temp, char scale);
double fromCelsius(double tempC, char targetScale);
void categorizeTemperature(double tempC);

int main() {
    double tempInput, convertedTemp, tempC;
    char originalScale, targetScale;

    printf("Enter the temperature value: ");
    scanf("%lf", &tempInput);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);
    originalScale = toupper(originalScale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);
    targetScale = toupper(targetScale);

    tempC = toCelsius(tempInput, originalScale);
    if (tempC == -9999) {
        printf("Invalid original scale entered.\n");
        return 1;
    }

    convertedTemp = fromCelsius(tempC, targetScale);
    if (convertedTemp == -9999) {
        printf("Invalid target scale entered.\n");
        return 1;
    }

    printf("Converted temperature: %.2lf %c\n", convertedTemp, targetScale);

    categorizeTemperature(tempC);

    return 0;
}

double toCelsius(double temp, char scale) {
    switch (scale) {
        case 'C':
            return temp;
        case 'F':
            return (temp - 32) * 5.0 / 9.0;
        case 'K':
            return temp - 273.15;
        default:
            return -9999;
    }
}

double fromCelsius(double tempC, char targetScale) {
    switch (targetScale) {
        case 'C':
            return tempC;
        case 'F':
            return (tempC * 9.0 / 5.0) + 32;
        case 'K':
            return tempC + 273.15;
        default:
            return -9999;
    }
}

void categorizeTemperature(double tempC) {
    printf("Temperature category: ");
    if (tempC < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Stay warm and avoid icy roads!\n");
    } else if (tempC < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (tempC < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather.\n");
    } else if (tempC < 35) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and stay hydrated!\n");
    }
}
