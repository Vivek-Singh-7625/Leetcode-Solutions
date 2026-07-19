class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(cost,n , dp);
    }
    int solve(vector<int>& cost , int idx , vector<int>& dp){
        if(idx == 0 or idx == 1)    return dp[idx] = 0;
        int one = 0 , two = 0;
        if(dp[idx] != -1)   return dp[idx];
        if(idx > 1) two = solve(cost,idx-2 , dp) + cost[idx-2];
        one = solve(cost,idx-1 , dp) + cost[idx-1];
        return dp[idx] =  min(one,two);
    }
};