//This is a C code on insertion sort.

#include<stdio.h>
void insort(int a[], int n);
int main()
{
    int array[50],i,n;
    printf("Size of array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of an array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    insort(array,n);
    printf("\nSorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

//function to perform the sorting
void insort(int a[], int n)
{
    int i,temp,j,k;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=temp;
  
    }
}

//If you want to see the process of sorting and the number of passes it takes to sort the array, take the bellow snippet of code and insert it at line 34

 // printf("Pass %d : ",i+1);
        // for(k=0;k<n;k++)
        // {
        //     printf("%d ",a[k]);
        // }
        // printf("\n");
