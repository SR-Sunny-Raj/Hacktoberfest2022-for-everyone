#include <bits/stdc++.h>
#include <stack>

using namespace std;
unordered_map<char,int> bracket={{'{',-1},{'[',-2},{'(',-3},{'}',1},{']',2},{')',3}};

string isBalanced(string s) {
stack< char> st;
       for(char symbol : s){
           
           if(bracket[symbol]<0){
           st.push(symbol);}
           else 
           {
               if(st.empty()) return "NO";
               char top = st.top();
               st.pop();
               if(bracket[top]+bracket[symbol]!=0){
                   return "NO";
                   
               }
           }
       }
       if(st.empty()) return"YES";
       else return"NO";
}


int main()
{
   int t ;
   cin>>t;
           while(t--){
       string s;
       cin>>s;
      cout<< isBalanced(s);
      cout<<endl;
      
}
    return 0;
}
