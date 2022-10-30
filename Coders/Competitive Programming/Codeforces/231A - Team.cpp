#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int arr[1000][1000];
    int total = 0;
    
    for(int i=0; i<n; i++) {
        int c = 0;
        for(int j=0; j<3; j++) {
            cin>>arr[i][j];
            if(arr[i][j]==1)
                c++;
        }
        if(c>1)
            total ++;
    }
    
    cout<<total;
 
    return 0;
}