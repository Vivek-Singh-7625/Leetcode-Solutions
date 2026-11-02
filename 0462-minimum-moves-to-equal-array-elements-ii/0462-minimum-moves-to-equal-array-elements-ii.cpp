class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        for(int& x : nums)  ans += abs(x - median);
        return ans;
    }
};