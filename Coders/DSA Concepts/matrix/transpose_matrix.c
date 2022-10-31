#include <stdio.h>

void transpose(int N, int matrix[][N])
{ int temp=0;
 for(int i=0;i<N;i++)
 {
     for(int j=0;j<N;j++)
     {  if(i<=j)
        {
             temp=matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
        } 
     }  
 }
    
}

int main()
{
    int r;
    scanf("%d",&r);
    int matrix[r][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++)
           scanf("%d",&matrix[i][j]);
    }
    transpose(r,matrix);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
           printf("%d ",matrix[i][j]);
        printf("\n");
    }
return 0;
}