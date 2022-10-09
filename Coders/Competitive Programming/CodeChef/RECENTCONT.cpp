//https://www.codechef.com/problems/RECENTCONT//

#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	    int n;
	    cin>>n;
	    string s[n];
	    for(int u=0;u<n;u++)
	    {
	        cin>>s[u];
	    }
	    int x=0;
        int y=0;	   
	    for(int u=0;u<n;u++)
	    {
	        if (s[u]=="START38")
	            x++;
	        else
	            y++;
	    }
	    cout<<x<<" "<<y<<endl;
	}
	return 0;
}