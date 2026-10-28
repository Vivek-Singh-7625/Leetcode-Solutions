class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , x ;
        vector<vector<vector<bool>>> dp(m , vector<vector<bool>> (n , vector<bool> (1024,false)));
        bool a , b;
        x = grid[0][0];
        dp[0][0][x] = true;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 and j == 0)   continue;
                x = grid[i][j];
                for(int k = 0 ; k < 1024 ; k++){
                    a = i ? dp[i-1][j][k] : 0;
                    b = j ? dp[i][j-1][k] : 0;
                    if(a)   dp[i][j][x^k] = true;
                    if(b)   dp[i][j][x^k] = true;
                }
            }
        }
        for(int k = 0 ; k < 1023 ; k++){
            if(dp[m-1][n-1][k]) return k;
        }
        return 1023;
    }
};