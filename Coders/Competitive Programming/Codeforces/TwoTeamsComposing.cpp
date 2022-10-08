/*
 Question link:- https://codeforces.com/problemset/problem/1335/C
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,max_freq=0,unique;
    cin>>n;
    unordered_map<int,int> bag;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        bag[element]++;
        max_freq=max(max_freq,bag[element]);
    }
   
    unique=bag.size();

    if(unique==max_freq)cout<<unique-1;
    else   cout<<min(unique,max_freq);
    cout<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
} 