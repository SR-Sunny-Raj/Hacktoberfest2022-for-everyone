#include <stdio.h>
int matSearch(int r,int c,int mat[][c],int x)
{
    int i=0,j=c-1;
    while(i<r && j>=0)
    {
        if(x==mat[i][j])
        {
            return 1; //key is found 
        }
        else if(mat[i][j]<x)
        {
            i++;
        }
        else
            j--;
    }
    return 0; //default when search is unsuccessfull
}
//input a rowwise and columnwise sorted matrix and 
//this code will return whether the searched key is present 
//in the matrix or not
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int matrix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
           scanf("%d",&matrix[i][j]);
    }
    int x;
    scanf("%d",&x);
    int result=matSearch(n,m,matrix,x);
    printf("%d\n",result);
return 0;
}