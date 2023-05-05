#include<iostream>
using namespace std;

void print_LCS(int i, int j, char** B, char* a) {
    if (i == 0 || j == 0) {
        return;
    }
    if (B[i][j] == '<') {
        print_LCS(i - 1, j - 1, B, a);
        cout << a[i] << " ";
    } else if (B[i][j] == '^') {
        print_LCS(i - 1, j, B, a);
    } else {
        print_LCS(i, j - 1, B, a);
    }
}

void LCS_Length(int n, int m, char* a, char* b) {
    int** c = new int*[n+1];
    char** B = new char*[n+1];
    for (int i = 0; i <= n; i++) {
        c[i] = new int[m+1];
        B[i] = new char[m+1];
    }
    for (int i = 0; i <= n; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        c[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                B[i][j] = '<';
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                B[i][j] = '^';
            } else {
                c[i][j] = c[i][j-1];
                B[i][j] = '>';
            }
        }
    }
    print_LCS(n, m, B, a);
    cout << endl;
    // free the allocated memory
    for (int i = 0; i <= n; i++) {
        delete[] c[i];
        delete[] B[i];
    }
    delete[] c;
    delete[] B;
}

int main() {
    int n, m;
    cout << "Enter total number of elements in first array: ";
    cin >> n;
    char* a = new char[n+1];
    cout << "Enter the elements of first array: ";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Enter total number of elements in second array: ";
    cin >> m;
    char* b = new char[m+1];
    cout << "Enter the elements of second array: ";
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    LCS_Length(n, m, a, b);
    // free the allocated memory
    delete[] a;
    delete[] b;
    return 0;
}
