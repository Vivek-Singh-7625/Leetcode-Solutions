class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n = text2.size() , x , y;
        vector<vector<int>> dp(m , vector<int> (n));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(text1[i] == text2[j]){
                    x = (i and j ) ? dp[i-1][j-1] : 0;
                    dp[i][j] = 1 + x;
                }
                else{
                    x = i ? dp[i-1][j] : 0;
                    y = j ? dp[i][j-1] : 0;
                    dp[i][j] = max(x,y);
                }
            }
        }
        return dp[m-1][n-1];
    }
};