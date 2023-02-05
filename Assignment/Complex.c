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

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }


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

    printf("(AC-BD):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("U[%d][%d] = %d\t", i, j, p[i][j] - q[i][j]);
        }
        printf("\n");
    }

    printf("(AD+BC)i:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("V[%d][%d] = %di\t", i, j, r[i][j] + s[i][j]);
        }
        printf("\n");
    }



    
}
else{
    printf("Rows should be equal to column:) \n");
}
    return 0;
}
