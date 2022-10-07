#include <bits/stdc++.h>
using namespace std;

int Linear_search(int size, int Array[], int Key)
{
    int i;

    for(i=0;i<size;i++)
    {
        if(Key==Array[i])
        {
            return i;
        }
    }
    return -1;
}



int main()
{
    int key, size, i, Result;
    
    cout<<"Enter the Size of Array: ";
    cin>>size;

    int Array[size];

    cout<<"Enter elements in Array"<<endl;

    for(i=0;i<size;i++)
    {
        cin>>Array[i];
    }

    Result = Linear_search(size, Array, key);

    if(Result==-1)
    {
        cout<<"Element not found."<<endl;
    }
    else
    {
        cout<<"Element is found at index: "<<Result<<endl;
    }

    return 0;
}