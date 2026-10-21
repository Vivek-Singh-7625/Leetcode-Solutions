class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length() , n = t.length();
        if(m < n)   return 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solver(0,0,s,t,dp);
    }
    int solver(int i , int j , string& s , string& t , vector<vector<int>>& dp){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solver(i+1,j+1,s,t,dp) + solver(i+1,j,s,t,dp);
        }
        return dp[i][j] = solver(i+1,j,s,t,dp);
    }
};