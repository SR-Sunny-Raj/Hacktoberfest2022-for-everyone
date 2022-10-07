//soldier and bananas 
//Problem Link -: https://codeforces.com/contest/546/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int k,n,w;
    cin>>k>>n>>w;
    long long sum=0;
    for (int i = 1; i <=w; i++)
    {
       sum = sum + (i*k);
    }
    if(sum<=n){
        cout<<"0"<<endl;
    }
 
    else 
    cout<< sum - n<<endl;
    return 0;
}
