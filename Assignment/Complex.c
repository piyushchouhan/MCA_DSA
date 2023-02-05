//c program which computes the product of two complex valued matrices (A, B) and (C, D)

#include<stdio.h>
#include<stdlib.h>


int main(){

int rows, colm;
int p[rows][colm],q[rows][colm],r[rows][colm],s[rows][colm];
printf("How many rows in matrices: ");
scanf("%d", &rows);
printf("How many columns in matrices: ");
scanf("%d",&colm);

printf("Matrix a\n");
int a[rows][colm];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }

printf("Matrix b\n");
int b[rows][colm];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    }

printf("Matrix c\n");
int c[rows][colm];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("b[%d][%d]=", i, j);
            scanf("%d", &c[i][j]);
        }
    }

printf("Matrix d\n");
int d[rows][colm];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            printf("d[%d][%d]=", i, j);
            scanf("%d", &d[i][j]);
        }
    }

for(int i=0;i<rows;i++)
{
    for(int j=0;j<colm;j++)
    {
        for(int k=0;k<rows;k++)
        {
            p[i][j]=p[i][j]+a[i][k]*c[k][j];
            q[i][j]=q[i][j]+b[i][k]*d[k][j];
            r[i][j]=r[i][j]+a[i][k]*d[k][j];
            s[i][j]=s[i][j]+b[i][k]*c[k][j];
        }
    }
 }

 printf("(AC-BD):\n");
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<colm;j++)
    {
        printf("U[%d][%d] = %d\t",i,j,p[i][j]-q[i][j]);
    }
    printf("\n");
 }

 printf("(AD+BC)i:\n");
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<colm;j++)
    {
        printf("V[%d][%d] = %di\t",i,j,r[i][j]+s[i][j]);
    }
    printf("\n");
 }
 return 0;



}
 