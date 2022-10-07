#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cout<<"Enter size of array"<<endl;
    cin>>a;
    int arr[a];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    // Return distance of first to maximum element
    cout << "Distance between first to max element: ";
    cout << distance(vect.begin(),max_element(vect.begin(), vect.end()));
    return 0;
}
