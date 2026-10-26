class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]);
            }
        }
        solver(ans, temp, 0, s, dp);
        return ans;
    }

    void solver(vector<vector<string>>& ans, vector<string>& temp,int idx,string& s, vector<vector<bool>>& dp) {
        int n = s.size();

        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (dp[idx][i]) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solver(ans, temp, i + 1, s, dp);
                temp.pop_back();
            }
        }
    }
};