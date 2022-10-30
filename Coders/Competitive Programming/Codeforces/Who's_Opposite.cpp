/*
    Question Link : https://codeforces.com/contest/1560/problem/B
    Who's Opposite?
*/

#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int a,b,c,diff;
		cin>>a>>b>>c;
		diff=abs(a-b);
	    if(a>2*diff || b>2*diff || c>2*diff)
	    	cout<<-1<<"\n";
	    else
	    {
	    	if(c+diff>2*diff)
	    		cout<<c-diff<<"\n";
	    	else
	    		cout<<c+diff<<"\n";
	    }
	}
	return 0;
}
