class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        int x ;
        for(int i = 0 ; i < n ; i++){
            for(int k = 1 ; k <= 3 ; k++){
                x = 1e9;
                if(i + k <= n)  dp[i+k] = min(dp[i] + costs[i+k-1] + k*k , dp[i+k]); 
            }
        }
        return dp[n];
    }
};