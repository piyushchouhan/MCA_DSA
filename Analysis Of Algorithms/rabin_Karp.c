//rabin karp
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void rabin_karp(char P[], char T[]) {
    int q = 13;
    int d = 10;
    int N = strlen(T); // Length of the text
    int M = strlen(P); // Length of the pattern
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the current window

    int h =(int) pow(d, M-1) % q;

    // Calculate the initial hash values of the pattern and the first window of the text
    for (int i = 0; i < M; i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (int s = 0; s <= N - M; s++) {
        if (p == t) {
            bool found = true;
            // Check for a match of characters
            for (int j = 0; j < M; j++) {
                if (T[s + j] != P[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                printf("Pattern found at index %d\n", s);
            }
        }

        // Calculate the hash value for the next window of the text
        if (s < N - M) {
            t = (d * (t - T[s] * h) + T[s + M]) % q;

            // If the hash value becomes negative, make it positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char text[] = "ABCABC";
    char pattern[] = "ABC";
    rabin_karp(pattern, text);
    return 0;
}
