#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open file
    FILE *file;
    file = fopen("AdventOfCode1.txt", "r");

    // If something goes wrong.
    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    // Int number will hold the number of a line.
    int number;
    // tempCal is the temp calorie counter.
    int tempCal = 0;
    // maxCal is the maximum calorie value at that moment. SecondCal and
    // thirdCal are second largest and third largest.
    int maxCal = 0;
    int secondCal = 0;
    int thirdCal = 0;

    // Used when reading file.
    char *line = NULL;
    size_t len = 0;

    // Will run till end of file.
    while (getline(&line, &len, file) != EOF) {
        // Making the line an integer.
        number = atoi(line);
        // Blank lines are automatically replaced with 0. That means 0 = end of
        // calorie group.
        if (number == 0) {
            // Entering this if() means tempCal is the largest meaning we need
            // to swift every val.
            if (tempCal > maxCal) {
                thirdCal = secondCal;
                secondCal = maxCal;
                maxCal = tempCal;
                // Entering this if() means tempCal is second largest meaning we
                // need to swift third and second.
            } else if (tempCal > secondCal) {
                thirdCal = secondCal;
                secondCal = tempCal;
                // Entering this if() means tempCal is third largest meaning we
                // only need to change third largest.
            } else if (tempCal >= thirdCal) {
                thirdCal = tempCal;
            }
            // resetting tempCal.
            tempCal = 0;
        }

        // Calculating tempCal.
        tempCal = tempCal + number;
    }

    // Calculating the combined calorie value of the three largest.
    int combinedCal = maxCal + secondCal + thirdCal;

    printf("%d\n", combinedCal);

    return 0;
}