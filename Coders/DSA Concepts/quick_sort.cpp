#include <bits/stdc++.h>
using namespace std;

int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int cnt=0;

    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);


    //partition
    int i=0,j=e;
    while (i<=pivotIndex && j>pivotIndex)
    {
        while (arr[pivotIndex]>=arr[i])i++;
        while(arr[pivotIndex]<arr[j])j--;

        if(i<pivotIndex && j>pivotIndex)swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
    

    
}

void quickSort(int *arr,int s,int e){
    // s is starting index and e is ending index
    if(s>=e)return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int n;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0; 
}