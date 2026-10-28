class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n);
        dp[0].push_back(grid[0][0]);
        vector<int> seen(1024, 0);
        int stamp = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)   continue;

                int x = grid[i][j];
                vector<int> next;
                ++stamp;

                auto addStates = [&](const vector<int>& states) {
                    for (int k : states) {
                        int val = k ^ x;

                        if (seen[val] != stamp) {
                            seen[val] = stamp;
                            next.push_back(val);
                        }
                    }
                };

                if (i > 0)
                    addStates(dp[j]);

                if (j > 0)
                    addStates(dp[j - 1]);

                dp[j] = move(next);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};