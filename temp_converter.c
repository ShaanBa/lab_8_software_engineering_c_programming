#include <stdio.h>

int main() {
    double temperature;
    // here ask for the input from the user for temp value
    printf("Enter the temperature value: ");
    scanf("%lf", &temperature);
        
    char original_scale;
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &original_scale);

    char target_scale;
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf("%c", &target_scale);

    return 0;
}