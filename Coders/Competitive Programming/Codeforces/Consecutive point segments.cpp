#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int t,n;
	cin>>t;
	while(t--)
	{
	   int count=0;
	   cin>>n;
	   vector<int>v(n);
	   for(int i=0;i<n;i++)
	    cin>>v[i];
	   	for(int i=0;i<n-1;i++)
	   		count=count+v[i+1]-v[i]-1;
	   	if(count<3)
	   		cout<<"YES"<<endl;
	   	else
	   		cout<<"NO"<<endl;
   }
	return 0;
}