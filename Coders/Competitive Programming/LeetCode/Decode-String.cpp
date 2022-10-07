// Problem link : https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else
            {
              string s1="";
              while(st.top()!='['){
                 s1+=st.top();
                 st.pop();
               }
               reverse(s1.begin(),s1.end());
               st.pop();
               string n="";
               while(!st.empty() && isdigit(st.top())){
                 n+=st.top();
                 st.pop();
              }
              reverse(n.begin(),n.end());
              int x=stoi(n);
              while(x--){
                 for(int i=0;i<s1.size();i++){
                    st.push(s1[i]);
                 }
              }
           }
        }
        string ans="";
        while(!st.empty()){
          ans+=st.top();
          st.pop();
         }  
        reverse(ans.begin(),ans.end());
        return ans;
    }
};