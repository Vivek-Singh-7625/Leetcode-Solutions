class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int take, not_take;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i - 1; j >= -1; j--) {
                take = 0;
                not_take = dp[i + 1][j + 1];
                if(j == -1 || nums[i] > nums[j])    take = 1 + dp[i + 1][i + 1];
                dp[i][j + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
};