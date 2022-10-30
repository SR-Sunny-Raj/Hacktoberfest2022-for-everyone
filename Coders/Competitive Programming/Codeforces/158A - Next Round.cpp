#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int limit=arr[k-1], ans=0;
    
    for(int i=0; i<n; i++) {
        if(arr[i]>=limit && arr[i]!=0)
            ans++;
        else
            break;
    }
    
    cout<<ans;
    return 0;
}