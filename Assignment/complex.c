//c program which computes the product of two complex valued matrices (A, B) and (C, D)

#include<stdio.h>
#include<stdlib.h>


int user_input(int rows, int colm);
int matrix_multiplication( int(*A)[][3], int(*B)[][3], int rows, int colm);

int user_input(int rows, int colm)
{
    int matrix[rows][colm];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("matrix[%d][%d]=", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix[rows][colm];
}

int matrix_multiplication( int(*A)[][3], int(*B)[][3], int rows, int colm)
{
    int C[rows][colm];
    for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colm; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < rows; k++)
                {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
            }
        }
    // return C[rows][colm];
}




int main()
{   
    int rows, colm;
    printf("How many rows in matrices: ");
    scanf("%d", &rows);
    printf("How many columns in matrices: ");
    scanf("%d",&colm);
    printf("input element in matrix A \n");
    int matrix_A = user_input(rows,colm);
    printf("Next matrix contain imaginary part of previous matrix\n");
    int matrix_B = user_input(rows,colm);
    printf("input element in matrix C \n");
    int matrix_C = user_input(rows,colm);
    printf("Next matrix contain imaginary part of previous matrix\n");
    int matrix_D = user_input(rows,colm);

    matrix_multiplication(matrix_A, matrix_C, rows, colm);
    int b = matrix_multiplication(matrix_B, matrix_D, rows, colm);
    int c = matrix_multiplication(matrix_A, matrix_D, rows, colm);
    int d = matrix_multiplication(matrix_B, matrix_C, rows, colm);



}




