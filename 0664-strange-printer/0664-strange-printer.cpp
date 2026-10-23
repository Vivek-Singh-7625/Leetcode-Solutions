class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;
                int x = l + 1;
                while (x <= r && s[x] == s[l])  x++;
                if (x > r)  dp[l][r] = 1;
                else {
                    dp[l][r] = 1 + dp[x][r];

                    for (int k = x; k <= r; k++) {
                        if (s[k] == s[l]) {
                            dp[l][r] = min( dp[l][r],dp[x][k - 1] + dp[k][r]);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};