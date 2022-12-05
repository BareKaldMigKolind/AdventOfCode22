#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to clear an array.
// Will be used to clear an array containging the similar chars from line 1
// and 2.
void clearArray(char array[], int n) {
    for (int i = 0; i <= n; i++) {
        array[i] = 0;
    }
}

int main() {
    // Open file
    FILE *file;
    file = fopen("input.txt", "r");
    // If open file doesn't go well..
    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    // sum holds the wanted value when the program is done.
    int sum = 0;
    // lineCounter will hold the number of lines at a given time.
    int lineCounter = 0;

    // This bool is used to break loops, if the similarchar has been found.
    bool charFound = false;

    // ch will be length of str -> length of line + ''\0'
    char ch1;
    char ch2;
    char ch3;

    // Array to hold charCarriers. The length is adjusted to fit the input data.
    // Ideally this should be calculated and automated, but I was lazy.Right now
    // it's lines/3
    char charArray[100];

    // simularArray holds each char that line 1 and 2 has in common.
    char similarArray[25];
    int similarCounter = 0;

    // essentially counts how many rounds the while loop has done
    int groupCounter = 0;

    // Array to calculate values of sum;
    char valueArray[52] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // These are used for reading a line of the input file. Copied for to use
    // for three lines
    char *line1 = NULL;
    size_t len1 = 0;

    char *line2 = NULL;
    size_t len2 = 0;

    char *line3 = NULL;
    size_t len3 = 0;

    // I'll acces the three lines in the group by ch1, ch2 ch3
    while ((ch1 = getline(&line1, &len1, file)) != EOF) {
        ch2 = getline(&line2, &len2, file);
        ch3 = getline(&line3, &len3, file);

        // These two for-loop compares first and second line. If a char is alike
        // it's saved in the similarArray.
        for (int i = 0; i < ch1; i++) {
            for (int j = 0; j < ch2; j++) {
                if (line1[i] == line2[j]) {
                    similarArray[similarCounter] = line1[i];
                    similarCounter++;
                    break;
                }
            }
        }
        // when the for loop is done, I will have an array consisting of each
        // similar char in line 1 and 2. The array is similarCounter long.

        for (int i = 0; i < ch3; i++) {
            if (charFound) {
                break;
            }
            for (int j = 0; j <= similarCounter; j++) {
                if (line3[i] == similarArray[j]) {
                    charArray[groupCounter] = line3[i];
                    groupCounter++;
                    charFound = true;
                    break;
                }
            }
        }

        // Updating and clearing data, so the new while-lap will start from "0"
        clearArray(similarArray, similarCounter);
        similarCounter = 0;
        lineCounter = lineCounter + 3;
        charFound = false;
    }

    // Calculating the value of each char.
    for (int i = 0; i < groupCounter; i++) {
        for (int j = 0; j < 52; j++) {
            if (charArray[i] == valueArray[j]) {
                // printf("char = %c\n", charArray[i]);
                sum = sum + (j + 1);
            }
        }
    }

    printf("%d", sum);

    fclose(file);
    return 0;
}
