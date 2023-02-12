// subtraction of matrix
#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k;
    int row1, row2, col1, col2;
    printf("What is the row of first matrix: \n");
    scanf("%d", &row1);
    printf("what is the column of first matrix: \n");
    scanf("%d", &col1);
    printf("What is the row of second matrix: \n");
    scanf("%d", &row2);
    printf("what is the column of second matrix: \n");
    scanf("%d", &col2);

    int a[row1][col1], b[row2][col2], subtract[row1][col1];

    // Taking the values in first matrix a //
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Taking the values in second matrix b //
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    if (row1 == row2 && col1 == col2)
    {
        // subtraction of both matrices--------------------
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                subtract[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    else
    {
        printf("We can't subtraction :) ");
    }

    // printing subtracted matrix
    printf("subtracted matrix is:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("%d\t", subtract[i][j]);
        }
        printf("\n");
    }

    return 0;
}