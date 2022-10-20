//CODEFORCES
//INCREASING 1742B
//https://codeforces.com/problemset/problem/1742/B


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            cout<<"YES"<<endl;
        }
        else{
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        
        bool flag=true;
        for(auto i: m){
            if(i.second>1)
            flag=false;
        }
        if(flag==false)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
        
    }
}
    return 0;
}