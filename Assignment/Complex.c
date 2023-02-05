// c program which computes the product of two complex valued matrices (A, B) and (C, D)

#include <stdio.h>

int main()
{

    int rows, colm,i,j,k;

    printf("How many rows in matrices: ");
    scanf("%d", &rows);
    printf("How many columns in matrices: ");
    scanf("%d", &colm);
    int a[rows][colm],b[rows][colm],c[rows][colm],d[rows][colm], p[rows][colm], q[rows][colm], r[rows][colm], s[rows][colm], U[rows][colm], V[rows][colm];
if(rows == colm){
    printf("Matrix a\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Matrix b\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("Matrix c\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("c[%d][%d]=", i, j);
            scanf("%d", &c[i][j]);
        }
    }

    printf("Matrix d\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("d[%d][%d]=", i, j);
            scanf("%d", &d[i][j]);
        }
    }

    // performing a*c, b*d, a*d, b*c
    for(i=0;i<rows;i++)
    {
        for(j=0;j<colm;j++)
        {
        p[i][j]=0;
        q[i][j]=0;
        r[i][j]=0;
        s[i][j]=0;
        for(k=0;k<rows;k++)
            {
                p[i][j]=p[i][j]+a[i][k]*c[k][j];
                q[i][j]=q[i][j]+b[i][k]*d[k][j];
                r[i][j]=r[i][j]+a[i][k]*d[k][j];
                s[i][j]=s[i][j]+b[i][k]*c[k][j];
            }
        }
    }

    // Performing the calculation of (ac-bd)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            U[i][j] = p[i][j] - q[i][j];
        }
    }

    // Performing the calculation of (ad+bc)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            V[i][j] = r[i][j] + s[i][j];
        }
    }

    // printing the whole new multiplied matrix
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
            printf("%d + %di\t", U[i][j], V[i][j]);
        printf("\n");
    }
}
else{
    printf("Rows should be equal to column:) \n");
}
    return 0;
}
