//https://www.codechef.com/LTIME112C/problems/EQUALIZEAB
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long a,b,x;
	    long long ans;
	    cin>>a>>b>>x;
	    if(a==b)
	    {
	        cout<<"YES"<<endl;
	    }
	    else{
	        ans=llabs(a-b);
	        if((ans!=x)&&(ans%(2*x)==0))
	        {
	            cout<<"YES"<<endl;
	        }
	        else{
	            cout<<"NO"<<endl;
	        }
	    }
	}
	return 0;
}
