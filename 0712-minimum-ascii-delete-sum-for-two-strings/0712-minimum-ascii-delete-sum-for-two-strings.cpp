class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length() , n = s2.length();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans = 0 , p = 0;
        for(int i = 0 ; i < m ; i++)    p += s1[i];
        for(int i = 0 ; i < n ; i++)    p += s2[i];
        ans = helper(s1 , s2 , 0 , 0 , dp);
        return p - 2*ans;
    }
    int helper(string& s1 , string& s2 , int i , int j , vector<vector<int>>& dp){
        if(i == s1.length() || j == s2.length())    return 0;;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = s1[i] + helper(s1,s2,i+1,j+1, dp);
        }
        return dp[i][j] = max(helper(s1 , s2 , i+1 , j , dp) , helper(s1 , s2 , i , j+1 , dp));
    }
};