class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(amount , coins , coins.size()-1 , dp);
    }
    int solve(int coin , vector<int>& coins , int idx , vector<vector<int>>& dp){
        if(coin < 0 or idx < 0)    return 0;
        if(coin == 0)   return dp[idx][coin] = 1;
        if(dp[idx][coin] != -1) return dp[idx][coin];
        int pick = solve(coin - coins[idx], coins , idx , dp);
        int not_pick = solve(coin, coins , idx-1 , dp);
        return dp[idx][coin] = pick + not_pick ; 
    }
};