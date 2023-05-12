#include <stdio.h>
#include <limits.h>


void matrixChainOrder(int p[], int n, int m[][8], int s[][8]);
void printOptimalParens(int s[][8], int i, int j);


void matrixChainOrder(int p[], int n, int m[][8], int s[][8]) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int s[][8], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        printf(")");
    }
}

int main() {
    int p[] = {5,10,3,12,5,50,6};
    int n = sizeof(p) / sizeof(p[0]);

    int m[8][8];
    int s[8][8];

    matrixChainOrder(p, n, m, s);

    printf("Minimum number of scalar multiplications: %d\n", m[1][n-1]);
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n-1);
    printf("\n");

    return 0;
}


