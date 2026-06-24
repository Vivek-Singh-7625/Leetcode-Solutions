class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = helper(coins , amount , dp) ;
        return ans == INT_MAX ? -1 : ans;
    }
    int helper(vector<int>& coins, int amount , vector<int>& dp){
        if(amount == 0) return  0;
        if(amount < 0)  return INT_MAX;
        if(dp[amount] != -1)    return dp[amount];
        int ans = INT_MAX, t;
        for(int i = 0 ; i < coins.size() ; i++) { 
            t = helper(coins,amount-coins[i],dp);
            if(t != INT_MAX)    ans = min(ans,t+1);
        }
        return dp[amount] = ans;
    }
};