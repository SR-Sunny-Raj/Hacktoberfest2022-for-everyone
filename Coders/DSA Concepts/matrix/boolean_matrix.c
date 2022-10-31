//modify each cell such that if element [i][j] is 1 then all the cells in the ith row and jth column becomes 1
//example:
//2 2
//10  => result will be 11
//00                    10
#include <stdio.h>
void booleanMatrix(int R, int C, int matrix[][C])
{   
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==1)
            {  
                for(int k=0;k<R;k++)
                   {if(matrix[k][j]==0) matrix[k][j]=2;}
        
                for(int k=0;k<C;k++)
                    {if(matrix[i][k]==0)matrix[i][k]=2;}
            }
           
        }
       
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==2)
                matrix[i][j]=1;
        }
    }
    
}

int main()
{
    int r,c;
    scanf("%d",&r);
    scanf("%d",&c);
    int matrix[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
           scanf("%d",&matrix[i][j]);
    }
    booleanMatrix(r,c, matrix);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
           printf("%d ",matrix[i][j]);
        printf("\n");
    }
return 0;
}