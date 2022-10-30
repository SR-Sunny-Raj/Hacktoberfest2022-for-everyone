#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int arr[N];

int main()
{
	int d,c=0, n; cin>>n;
	map<int,int> ans;
    map<int,vector<int>> m;
    for (int i = 1; i <=n; ++i)
    {
    	int x; cin>>x;
    	m[x].push_back(i);
    }
    for (auto value : m)
    {
    	int f=0;
    	if((value.second).size() == 1){
    		ans[value.first] = 0;
    		 c++;
    	}
    	else
    	{
	    	d = value.second[1] - value.second[0];
	    	for(int i=1; i< value.second.size()-1; i++)
	    	{
	    		int dtemp = m[value.first][i+1] - m[value.first][i];
	    		if(d != dtemp)
	    		{
	    			f=1;
	    			break;
	    		} 
	    	}
	    	if(f==0)
	    	{
	    		c++;
	    		ans[value.first] = d;
	    	}
	    }
    }
    cout<<c<<endl;
    for(auto it : ans)
    {
    	cout<<it.first<<" "<<it.second<<endl;
    }
}
