class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solver(0, 0, word1, word2, dp);
    }

    int solver(int i, int j, string& w1, string& w2,vector<vector<int>>& dp) {
        if (i == w1.size()) return w2.size() - j;
        if (j == w2.size()) return w1.size() - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (w1[i] == w2[j]) {
            return dp[i][j] = solver(i + 1, j + 1, w1, w2, dp);
        }
        int replace = solver(i + 1, j + 1, w1, w2, dp);
        int insert = solver(i, j + 1, w1, w2, dp);
        int del = solver(i + 1, j, w1, w2, dp);
        return dp[i][j] = 1 + min({replace, insert, del});
    }
};