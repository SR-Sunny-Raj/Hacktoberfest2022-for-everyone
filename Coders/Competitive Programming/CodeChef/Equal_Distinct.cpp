// Url: https://www.codechef.com/submit/EQDIS

#include <bits/stdc++.h>
using namespace std;

int main() {

	int cases;
	cin>>cases;
	while(cases--){
	    int n;
	    cin>>n;
	    int array_s[n];
	    for(int i=0;i<n;i++){
	        cin>>array_s[i];
	    }
	    unordered_set<int> a;
	    int uni =0;
	    for(int i=0;i<n;i++){
	        if(a.find(array_s[i])== a.end()){
	            a.insert(array_s[i]);
	            uni++;
	        }
	    }
	    if(n%2 !=0 && uni == n){
	        cout<<"NO"<<endl;
	    }
	    else
	        cout<<"YES"<<endl;
	}
	return 0;
}
