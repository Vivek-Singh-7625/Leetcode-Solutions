class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() , n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1e9));
        solver(0 , 0 , dungeon , dp);
        return max(1 + dp[0][0],1);
    }
    int solver(int r , int c , vector<vector<int>>& a , vector<vector<int>>& dp){
        int m = a.size() , n = a[0].size();
        if(r == m - 1  and c == n - 1)  return dp[r][c] = (a[r][c] > 0 ? 0 : -a[r][c]);
        if(dp[r][c] != -1e9)   return dp[r][c];
        int right = 1e9 , down = 1e9;
        if(r < m-1) down = -a[r][c] + solver(r+1,c,a,dp);   
        if(c < n-1) right = -a[r][c] + solver(r,c+1,a,dp);  
        return dp[r][c] = (min(down,right) < 0 ? 0 : min(down,right));
    }
};