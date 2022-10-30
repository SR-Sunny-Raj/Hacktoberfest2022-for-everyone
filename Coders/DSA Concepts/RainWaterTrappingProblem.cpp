#include<bits/stdc++.h>
using namespace std;
int trappingRainwater(int arr[],int n)
{
	stack<int> s;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		while((!s.empty())&&arr[s.top()]<arr[i])
		{
			int pop_height=arr[s.top()];
			s.pop();
			if(s.empty())
			break;
			int dis=i-s.top()-1;
			int mn=min(arr[s.top()],arr[i])-pop_height;
			ans+=dis*mn;
		}
		s.push(i);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=trappingRainwater(arr,n);
	cout<<ans<<endl;
	return 0;
}
