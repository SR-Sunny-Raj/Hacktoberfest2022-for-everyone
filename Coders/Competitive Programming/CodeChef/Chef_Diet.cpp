// Problem Link : https://www.codechef.com/problems/DIET

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T,N,i,flag;
	long K;
	cin>>T;
	while(T--)
	{
	    cin>>N>>K;
	    long A[N],Sum;
        // Used Sum variable here to represent left over from previous iteration  
	    Sum=0;
	    for(i=1;i<=N;i++)
	        cin>>A[i];
	    for(i=1;i<=N;i++)
	    {
	        flag=0;
	       if((Sum+A[i])<K) 
	       {
	           flag=i;
	           break;
	       }
	       Sum=Sum+(A[i]-K);
	    }
	    if(flag!=0)
	    cout<<"NO"<<" "<<flag<<"\n";
	    else
	    cout<<"YES"<<"\n";
	}
	return 0;
}
