// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/

// Solution:

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), 0));
        int len = 1, start, end;
        for (int i = 0; i < s.length(); i++) dp[i][i] = 1, len = 1, start = i, end = i;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = 1, len = 2, start = i, end = i + 1;
        }
        for (int i = 3; i <= s.length(); i++) {
            for (int j = 0; j < s.length() - i + 1; j++) {
                int k = j + i - 1;
                if (dp[j + 1][k - 1] == 1 && s[j] == s[k]) {
                    dp[j][k] = 1 + dp[j][k];
                    if (k - j + 1 > len) {
                        len = k - j + 1;
                        start = j;
                        end = k;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};