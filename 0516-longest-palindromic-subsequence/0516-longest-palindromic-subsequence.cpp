class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n , vector<int> (n,-1));
        int ans = helper(s , 0 , n-1 , dp);
        return ans;
    }
    int helper(string& s , int i , int j , vector<vector<int>>& dp){
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = helper(s , i+1 , j-1 , dp)  + (i != j ? 2 : 1);
        }
        return dp[i][j] = max(helper(s , i+1 , j , dp) , helper(s , i , j-1 , dp));
    }
};