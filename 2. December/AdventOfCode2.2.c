#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Det gik skidt");
        return -1;
    }

    int sum = 0;
    int rock = 1;
    int paper = 2;
    int scissor = 3;

    int win = 6;
    int draw = 3;
    int loss = 0;

    char them;
    char space;
    char result;
    char newLine;

    while ((them = getc(file)) != EOF) {
        space = getc(file);
        result = getc(file);
        newLine = getc(file);

        // WIN
        if (result == 'Z') {
            sum = sum + win;
            if (them == 'A') {
                sum = sum + paper;
            } else if (them == 'B') {
                sum = sum + scissor;
            } else if (them == 'C') {
                sum = sum + rock;
            }

            // DRAW
        } else if (result == 'Y') {
            sum = sum + draw;
            if (them == 'A') {
                sum = sum + rock;
            } else if (them == 'B') {
                sum = sum + paper;
            } else if (them == 'C') {
                sum = sum + scissor;
            }

            // Loss
        } else if (result == 'X') {
            if (them == 'A') {
                sum = sum + scissor;
            } else if (them == 'B') {
                sum = sum + rock;
            } else if (them == 'C') {
                sum = sum + paper;
            }
        }
    }

    printf("%d\n", sum);

    fclose(file);
    return 0;
}
