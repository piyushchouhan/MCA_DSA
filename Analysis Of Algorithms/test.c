#include <stdio.h>

void lcs_length(char x[], char y[]);
int print_lcs(char b[][7], char x[], int i, int j);

void lcs_length(char x[], char y[]) {
    char b[8][7];
    int c[8][7];

    for (int i = 0; i <= 7; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= 6; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 6; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '/';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '!';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '^';
            }
        }
    }
    print_lcs(b, x, 7, 6);
}

int print_lcs(char b[][7], char x[], int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (b[i][j] == '/') {
        print_lcs(b, x, i - 1, j - 1);
        printf("%c", x[i]);
    } else if (b[i][j] == '!') {
        print_lcs(b, x, i - 1, j);
    } else {
        print_lcs(b, x, i, j - 1);
    }
}

int main() {
    char x[] = { ' ','A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[] = { ' ','B', 'D', 'C', 'A', 'B', 'A'};
    lcs_length(x, y);

    return 0;
}

