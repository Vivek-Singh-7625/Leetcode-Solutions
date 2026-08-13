class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1 , sp = 0  , n = s.length() , j;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (len > max_len) {
                        max_len = len;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,max_len);
    }
};