class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int> (n,-1)); 
        // for(int i = 0 ; i < n ; i++)    dp[i][i] = 1;
        // for(int i = 1 ; i < n ; i++){
        //     for(int j = 0 ; j < i ; j++){
        //         int x = i+1;
        //         while(i < )
        //     }
        // }
        return solver(0,n-1,s,dp);
    }
    int solver(int l, int r, string& s , vector<vector<int>>& dp){
        if(l > r)   return 0;
        if(l == r)  return dp[l][r] = 1;
        if(dp[l][r] != -1)  return dp[l][r];

        int i = l+1 , n = s.length();
        while(i < r  and s[i] == s[l])  i++;
        if(i > r) return dp[l][r] = 1;
        int ans1 = 1 + solver(i,r,s,dp);
        
        for(int j = i ; j <= r ; j++){
            if(s[j] == s[l]){
                ans1 = min(ans1 , solver(i,j-1,s,dp) + solver(j,r,s,dp));
            }
        }
        return dp[l][r] = ans1;
    }
};