class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() , n = dungeon[0].size() , down , right;
        vector<vector<int>> dp(m,vector<int> (n,-1e9));
        dp[m-1][n-1] = (dungeon[m-1][n-1] > 0 ? 0 : -dungeon[m-1][n-1]);
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i == m-1 and j == n-1)   continue;
                down = 1e9;
                right = 1e9;
                if(i < m-1) down = dp[i+1][j] - dungeon[i][j];
                if(j < n-1) right = dp[i][j+1] - dungeon[i][j];
                dp[i][j] = (min(down,right) < 0 ? 0 : min(down,right));
            }
        }
        return max(1 + dp[0][0],1);
    }
};