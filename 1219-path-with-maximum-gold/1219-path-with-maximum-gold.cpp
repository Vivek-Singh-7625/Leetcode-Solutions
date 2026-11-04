class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j])  ans = max(ans, solver(grid, i, j, m, n));
            }
        }
        return ans;
    }

    int solver(vector<vector<int>>& grid, int x, int y, int m, int n) {
        if(x < 0 or y < 0 or x >= m or y >= n or grid[x][y] == 0)   return 0;

        static int r[4] = {1, -1, 0, 0};
        static int c[4] = {0, 0, 1, -1};
        int t = grid[x][y], ans = 0;

        grid[x][y] = 0;
        for(int i = 0; i < 4; i++)  ans = max(ans, solver(grid, x + r[i], y + c[i], m, n));
        grid[x][y] = t;

        return t + ans;
    }
};