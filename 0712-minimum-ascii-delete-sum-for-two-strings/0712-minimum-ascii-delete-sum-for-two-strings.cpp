class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length() , n = s2.length() , x , y;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans = 0 , p = 0;
        for(int i = 0 ; i < m ; i++)    p += s1[i];
        for(int i = 0 ; i < n ; i++)    p += s2[i];
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(s1[i] == s2[j]){
                    if(i == m-1 or j == n-1)    x = 0;
                    else    x = dp[i+1][j+1];
                    dp[i][j] = s1[i] + x;
                }
                else{
                    if(i == m-1)    x = 0;
                    else    x = dp[i+1][j];
                    if(j == n-1)    y = 0;
                    else    y = dp[i][j+1];
                    dp[i][j] = max(x,y);
                }
            }
        }
        return p - 2*dp[0][0];
    }
};