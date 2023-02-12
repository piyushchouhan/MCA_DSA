#include <stdio.h>
int main()
{
    int p1[10], p2[10], p3[10], m, n, k, y, i, j, x;
    printf("\n\tPolynomial Addition:\n");
    printf("\t.........................\n");
    printf("\n\tEnter the no. of terms of the polynomial:");
    scanf("%d", &m);
    printf("\n\tEnter the degrees and coefficients:");
    for (i = 0; i < 2 * m; i++)
        scanf("%d", &p1[i]);
    printf("\n\tFirst polynomial is:");
    y = 0;
    if (p1[y + 1] == 1)
        printf("x^%d", p1[y]);
    else
        printf("%dx^%d", p1[y + 1], p1[y]);
    y += 2;
    while (y < i)
    {
        printf("+%dx^%d", p1[y + 1], p1[y]);
        y += 2;
    }
    printf("\n\n\n\tEnter the no. of terms of 2nd polynomial:");
    scanf("%d", &n);
    printf("\n\tEnter the degrees and co-efficients:");
    for (j = 0; j < 2 * n; j++)
        scanf("%d", &p2[j]);
    printf("\n\tSecond polynomial is:");
    y = 0;
    if (p2[y + 1] == 1)
        printf("x^%d", p2[y]);
    else
        printf("%dx^%d", p2[y + 1], p2[y]);
    y += 2;
    while (y < 2 * n)
    {
        printf("+%dx^%d", p2[y + 1], p2[y]);
        y += 2;
    }
    i = 0;
    j = 0;
    k = 0;
    while (m > 0 && n > 0)
    {
        if (p1[i] == p2[j])
        {
            p3[k + 1] = p1[i + 1] + p2[j + 1];
            p3[k] = p1[i];
            m--;
            n--;
            i += 2;
            j += 2;
        }
        else if (p1[i] > p2[j])
        {
            p3[k + 1] = p1[i + 1];
            p3[k] = p1[i];
            m--;
            i += 2;
        }
        else
        {
            p3[k + 1] = p2[j + 1];
            p3[k] = p2[j];
            n--;
            j += 2;
        }
        k += 2;
    }
    while (m > 0)
    {
        p3[k + 1] = p1[i + 1];
        p3[k] = p1[i];
        k += 2;
        i += 2;
        m--;
    }
    while (n > 0)
    {
        p3[k + 1] = p2[j + 1];
        p3[k] = p2[j];
        k += 2;
        j += 2;
        n--;
    }
    printf("\n\n\n\n\tSum of the two polynomials is:");
    y = 0;
    if (p3[y + 1] == 1)
        printf("x^%d", p3[y]);
    else
        printf("%dx^%d", p3[y + 1], p3[y]);
    y += 2;
    while (y < k)
    {
        if (p3[y + 1] == 1)
            printf("+x^%d", p3[y]);
        else
            printf("+%dx^%d", p3[y + 1], p3[y]);
        y += 2;
    }
    return 0;
}