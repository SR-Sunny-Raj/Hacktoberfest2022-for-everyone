/*
CodeChef Problem: Binary Substitution
Problem code: BINARYSUB
Description:
Chef has a binary string SS. He can replace any occurrence of -

0101 with aa
1010 with bb
010010 with abab
101101 with baba
While doing these operations, Chef noticed that he can end up with different strings depending upon the order of application of the operations. 
Given the final string containing only aa and bb, Chef wants to know the number of possible strings he might have began with.
As the number of initial strings can be large, print the result modulo 998244353998244353.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line of input denoting SS, the final string obtained after applying the operations.

Output Format
For each test case, output the number of original strings that can result in the final string mod 998244353998244353.

Constraints
1≤T≤5⋅10^4
1≤∣S∣≤10^5
The sum of |S| over all test cases won't exceed 5.10^5
S consists of aa and bb only.

Sample 1:
Input
3
ab
aa
abb

Output
2
1
2

Explanation:
Test case 1: The binary strings that can result in the string abab are 01100110 and 010010.
  01100110: Replace the first two characters 0101 with aa and last two characters 1010 with bb. Thus, we get abab.
  010010: Replace the characters 010010 with abab.
  
Test case 2: The only binary string that can result in the string aaaa is 01010101. In 01010101, we replace the first two characters with aa and last two characters with aa as well.

Test case 3: The binary strings that can result in the string abbabb are 011010011010 and 0101001010.
 011010011010: Replace the first two characters 0101 with aa, next two characters 1010 with bb, and last two characters 1010 with bb. Thus, we get abbabb.
 0101001010: Replace the characters 010010 with abab and the characters 1010 with bb.
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool a[100001];
int dp[100001][2];

void solve(){
   int n;string s;
   cin >> s;n=s.size();
   for(int i=1;i<n;++i)
      a[i]=s[i]!=s[i-1];
  
   dp[0][0]=1;
   for(int i=1;i<n;++i) {
      dp[i][0]=(dp[i-1][0]+dp[i-1][1])%998244353;
      if(a[i]==1) dp[i][1]=dp[i-1][0];
      else dp[i][1]=0;
   }
   cout << (dp[n-1][0]+dp[n-1][1])%998244353 << endl;
  
}

int32_t main() {
   int T;cin >> T;
   while(T--) solve();
}
