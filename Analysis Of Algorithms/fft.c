#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void recursive_fft(double complex *a, double complex *y, int n) {
    if (n == 1) {
        y[0] = a[0];
        return;
    }

    double complex wn = cexp(2 * M_PI * I / n);
    double complex w = 1;
    double complex a0[n / 2];
    double complex a1[n / 2];

    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    double complex y0[n / 2];
    double complex y1[n / 2];
    recursive_fft(a0, y0, n / 2);
    recursive_fft(a1, y1, n / 2);

    for (int k = 0; k < n / 2; k++) {
        y[k] = y0[k] + w * y1[k];
        y[k + n / 2] = y0[k] - w * y1[k];
        w = w * wn;
    }
}

int main() {
    int n = 4;
    double complex a[] = {1, 2, 3, 4};
    double complex y[n];

    recursive_fft(a, y, n);

    for (int i = 0; i < n; i++) {
        printf("y[%d] = %.2f + %.2fi\n", i, creal(y[i]), cimag(y[i]));
    }

    return 0;
}

// This code uses the C99 standard, 
// which supports complex numbers.
// Make sure to compile the code with a C99-compatible compiler,
// such as GCC, using the -std=c99 flag:

//gcc -std=c99 fft.c -o fft -lm
