class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,10000);
        dp[n] = 0;
        for(int i = n ; i >= 0 ; i--){
            solve(dp,i);
        }
        return dp[0];
    }
    void solve(vector<int>& dp , int n){
        for(int i = 1 ; i*i <= n ; i++){
            dp[n-i*i] = min(dp[n] + 1,dp[n-i*i]);
        }
    }
};