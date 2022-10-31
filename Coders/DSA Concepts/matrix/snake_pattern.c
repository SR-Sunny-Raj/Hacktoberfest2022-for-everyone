#include <stdio.h>
int* snakePattern(int n, int matrix[][n])
{       
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n/2;k++)
        {
        if(i%2!=0)
        {
              int temp=matrix[i][k];
              matrix[i][k]=matrix[i][n-1-k];
              matrix[i][n-1-k]=temp;
        }
    }}
return matrix;
}

int main()
{
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
           scanf("%d",&matrix[i][j]);
    }
    int *result=snakePattern(n, matrix);
    for(int i=0;i<n*n;i++)
        printf("%d ",result[i]);
    printf("\n");
return 0;
}