https://www.codechef.com/viewsolution/76359344
SINGLE SOLUTION 2
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	   string a;
	   cin>>a;
	    int count=0;
	    for(int i=0;i<n;i++){
	       count++;
	        if(a[i+1]==49)
	       
	         break;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
