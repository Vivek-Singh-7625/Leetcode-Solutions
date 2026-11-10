class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return solver(dp,costs,n);
    }
    int solver(vector<int>& dp , vector<int>& c , int idx){
        if(idx < 0) return 1e9;
        if(idx == 0) return 0;
        if(dp[idx] != -1)   return dp[idx];
        int x = c[idx-1] + 1 + solver(dp,c,idx-1);
        int y = c[idx-1] + 4 + solver(dp,c,idx-2);
        int z = c[idx-1] + 9 + solver(dp,c,idx-3);
        return dp[idx] = min(x,min(y,z));
    }
};