class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size() , x , n = grid[0].size() , N = m * n;
        vector<int> freq(N + 1, 0);
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                x = grid[i][j];
                freq[x]++;
                if (freq[x] == 2) {
                    ans.push_back(x);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};