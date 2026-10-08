class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n = text2.size();
        vector<int> dp(n , 0);
        for(int i = 0 ; i < m ; i++){
            int x = 0;
            for(int j = 0 ; j < n ; j++){
                int y = dp[j];
                if(text1[i] == text2[j])    dp[j] = x + 1;
                else    dp[j] = max(dp[j] , j ? dp[j-1] : 0);
                x = y;
            }
        }
        return dp[n-1];
    }
};