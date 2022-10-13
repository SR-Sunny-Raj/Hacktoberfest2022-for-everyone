class Solution {
public:
    vector<int> getRow(int n) 
    {
        vector<int>v(n+1);
        v[0]=1;
        for(int i=1;i<=n;i++)
        {
		// converting int in to long long because for n>=30 number is not in range of int
          v[i]=(long long)v[i-1]*(n+1-i)/i;
        }
        return v;
    }
};
