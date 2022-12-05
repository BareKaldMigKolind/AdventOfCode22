#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open file
    FILE *file;
    file = fopen("AdventOfCode1.txt", "r");

    // If fopen doesn't go well
    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    // Number will hold the line number.
    int number;
    // tempCal is the temp calorie counter.
    int tempCal = 0;
    // maxCal is the highest calorie sum registered at that moment.
    int maxCal = 0;

    // These are used for reading the file.
    char *line = NULL;
    size_t len = 0;

    // While loop to trav through the file.
    while (getline(&line, &len, file) != EOF) {
        // Making the stringed number a number.
        number = atoi(line);

        // Blank lines are automatically replaced with 0. That means 0 = end of
        // calorie group.
        if (number == 0) {
            // Comparing tempCal and maxCal
            if (tempCal > maxCal) {
                // Changing maxCal to tempCal.
                maxCal = tempCal;
            }
            // Resetting tempCal
            tempCal = 0;
        }

        // Summing the calorie group.
        tempCal = tempCal + number;
    }

    printf("%d\n", maxCal);

    return 0;
}