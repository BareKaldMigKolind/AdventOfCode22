#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open file
    FILE *file;
    file = fopen("input.txt", "r");
    // If open file doesn't go well..
    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    // length will hold length of each line
    int length;
    // compSize will hold length of each compartment
    int compSize;
    // sum holds the wanted value when the program is done.
    int sum = 0;
    // lineCounter will hold the number of lines at a given time.
    int lineCounter = 0;
    // ch will be length of str -> length of line + ''\0'
    char ch;

    // Array to hold charCarriers. The length is adjusted to fit the input data.
    // Ideally this should be calculated and automated, but I was lazy.
    char charArray[300];

    // Array to calculate values of sum;
    char valueArray[52] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // These are used for reading a line of the input file.
    char *line = NULL;
    size_t len = 0;

    // While loop to trav through the file.
    while ((ch = getline(&line, &len, file)) != EOF) {
        // Number of characters are ch - 1.
        length = ch - 1;
        // Size of each compartment is length/2
        compSize = length / 2;

        // Comparing first half of line with second half of line.
        // If two chars are alike, I add it to the charArray.
        for (int i = 0; i < compSize; i++) {
            for (int j = compSize; j < length; j++) {
                if (line[i] == line[j]) {
                    charArray[lineCounter] = line[j];
                }
            }
        }
        lineCounter++;
    }

    // Calculating the value of each char.
    for (int i = 0; i < lineCounter; i++) {
        for (int j = 0; j < 52; j++) {
            if (charArray[i] == valueArray[j]) {
                sum = sum + (j + 1);
            }
        }
    }
    printf("%d", sum);

    fclose(file);
    return 0;
}
