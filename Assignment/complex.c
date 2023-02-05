// c program which computes the product of two complex valued matrices (A, B) and (C, D)

#include <stdio.h>
#include <stdio.h>
void user_input(int rows, int colm, int matrix[rows][colm]);

void user_input(int rows, int colm, int matrix[rows][colm])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("matrix[%d][%d]=", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main()
{
    int rows, colm,i,j,k;
    printf("How many rows in matrices: ");
    scanf("%d", &rows);
    printf("How many columns in matrices: ");
    scanf("%d", &colm);
    int  p[rows][colm], q[rows][colm], r[rows][colm], s[rows][colm], U[rows][colm], V[rows][colm];
    int Matrix_A[rows][colm];
    int Matrix_B[rows][colm];
    int Matrix_C[rows][colm];
    int Matrix_D[rows][colm];
    printf("Matrix A\n");
    user_input(rows, colm, Matrix_A);
    printf("Matrix B\n");
    user_input(rows, colm, Matrix_B);
    printf("Matrix C\n");
    user_input(rows, colm, Matrix_C);
    printf("Matrix D\n");
    user_input(rows, colm, Matrix_D);
    
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
            p[i][j]=p[i][j]+Matrix_A[i][k]*Matrix_C[k][j];
            q[i][j]=q[i][j]+Matrix_B[i][k]*Matrix_D[k][j];
            r[i][j]=r[i][j]+Matrix_A[i][k]*Matrix_D[k][j];
            s[i][j]=s[i][j]+Matrix_B[i][k]*Matrix_C[k][j];
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

    printf("Number of multiplications: %d\n", 4*(rows * colm * colm));
    printf("Number of additions: %d\n", 4*(rows* colm * ( colm - 1)));
}
