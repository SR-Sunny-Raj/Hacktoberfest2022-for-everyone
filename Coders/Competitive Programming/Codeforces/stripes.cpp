//CODEFORCES 
//1742C-STRIPES
//https://codeforces.com/problemset/problem/1742/C

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        char a[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
            cin>>a[i][j];
            }
        }
        bool red=false;
        int countr=0;
        for(int i=0;i<8;i++){
            countr=0;
            for(int j=0;j<8;j++){
                if(a[i][j]=='R')
                countr++;
            }
            if(countr==8){
                red=true;
                break;
            }
        }
        if(red==true)
        cout<<"R"<<endl;
        else
        cout<<"B"<<endl;
}
    return 0;
}