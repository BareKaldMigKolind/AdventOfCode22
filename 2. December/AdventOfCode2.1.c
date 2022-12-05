#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // open file
    FILE *file;
    file = fopen("input.txt", "r");

    // If something goes wrong
    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    // Sum will hold the calculated values.
    int sum = 0;

    // These are just for visualization of the values in the code.
    int rock = 1;
    int paper = 2;
    int scissor = 3;

    int win = 6;
    int draw = 3;
    int loss = 0;

    // These are for reading the file with getc().
    char them;
    char space;
    char me;
    char newLine;

    // Will run until end of file.
    while ((them = getc(file)) != EOF) {
        space = getc(file);
        me = getc(file);
        newLine = getc(file);

        // The big if maze. The outer ifs are for A, B and C.
        // Inner ifs are for each putput based on "my" value.
        if (them == 'A') {
            if (me == 'X') {
                sum = sum + draw + rock;

            } else if (me == 'Y') {
                sum = sum + win + paper;

            } else if (me == 'Z') {
                sum = sum + loss + scissor;
            }

        } else if (them == 'B') {
            if (me == 'X') {
                sum = sum + loss + rock;

            } else if (me == 'Y') {
                sum = sum + draw + paper;

            } else if (me == 'Z') {
                sum = sum + win + scissor;
            }

        } else if (them == 'C') {
            if (me == 'X') {
                sum = sum + win + rock;

            } else if (me == 'Y') {
                sum = sum + loss + paper;

            } else if (me == 'Z') {
                sum = sum + draw + scissor;
            }
        }
    }

    printf("%d\n", sum);

    fclose(file);
    return 0;
}
