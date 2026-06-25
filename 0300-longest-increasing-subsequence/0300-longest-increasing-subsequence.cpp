class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int shift = min(0, mn);
        int t = mx + 1;
        int rows = t - shift + 1;
        vector<vector<int>> dp(rows, vector<int>(n, -1));
        return count(nums, n - 1, t, dp, shift);
    }
    int count(vector<int>& nums, int idx, int prev,vector<vector<int>>& dp, int mn) {
        if (idx < 0) return 0;
        if (dp[prev - mn][idx] != -1)    return dp[prev - mn][idx];
        int take = 0;
        if (nums[idx] < prev)   take = 1 + count(nums, idx - 1, nums[idx], dp, mn);
        int not_take = count(nums, idx - 1, prev, dp, mn);
        return dp[prev - mn][idx] = max(take, not_take);
    }
};