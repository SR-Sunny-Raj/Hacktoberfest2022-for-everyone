https://www.codechef.com/viewsolution/76360631
SINGLE OPERATION 1
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
	    for(int i=0;a[i]!=0;i++){
	      
	        if(a[i]==49)
           count++;
         else
	         break;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
