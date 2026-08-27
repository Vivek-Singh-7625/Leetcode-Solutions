class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i = n ; i >= 0 ; i--){
            for(int j = 1 ; j*j <= i ; j++){
                if(dp[i-j*j])   dp[i-j*j] = min(dp[i-j*j],dp[i] + 1);
                else    dp[i-j*j] = dp[i] + 1;
            }
        }
        return dp[0];
    }
};