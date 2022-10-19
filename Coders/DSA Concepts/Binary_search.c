#include <stdio.h>
#include <stdlib.h>
//Binary Search
int main()
{
	int n,i,flag=0,key,mid;
	printf("Enter the number of elements you want in your list : ");
	scanf("%d",&n);
	int arr[n],UB=n-1,LB=0;
	printf("\nEnter the sorted elements in the list : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the data you want to search in the list : ");
	scanf("%d",&key);
	while(LB<=UB)
	{
	mid=(UB+LB)/2;
	if(arr[mid]==key)
	{
		printf("\nData found at index %d",mid);
		flag=1;
		break;
	}
	else if(arr[mid]<key)
	{
		LB=mid+1;
	}
	else if(arr[mid]>key)
	{
		UB=mid-1;
	}
	}
	if(flag==0)
	{
		printf("\nData not found in the list!!");
	}
	return 0;
}
