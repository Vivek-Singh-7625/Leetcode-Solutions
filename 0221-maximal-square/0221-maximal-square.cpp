class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() , ans = 0;
        vector<vector<int>> dp(m,vector<int> (n));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                dp[i][j] = matrix[i][j] - '0';
                if(i and j and dp[i][j]){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                }
                ans = max(dp[i][j],ans);
            }
        }
        return ans*ans;
    }
};