class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0 , sp = 0 , len , n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i = 0; i < n ; i++){
            len = 0;
            for(int j = i ; j < n ; j++){
                len++;
                if(s.length()-i < max_len)   break;
                if(solve(i,j,s,dp) == true){
                    if(max_len < len){
                        max_len = len;
                        sp = i;
                    }
                }  
            }
        }
        return s.substr(sp,max_len);
    }
    bool solve(int& x , int& y , string& s , vector<vector<bool>>& dp){
        int len = y - x + 1;
        for(int i = 0 ; i < len/2 ; i++){
            if(dp[x+i][y-i])    break;
            if(s[x+i] != s[y-i])    return false;
        }
        return dp[x][y] = true;
    }
};