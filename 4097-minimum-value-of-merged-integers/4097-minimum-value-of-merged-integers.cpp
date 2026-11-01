class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX , b , p , n = nums.size();
        for (int i = 0 ; i < n ; i += 2) {
            b = nums[i + 1];
            if (b < 10) p = 10;
            else if (b < 100) p = 100;
            else if (b < 1000) p = 1000;
            else if (b <= 10000) p = 10000;
            else if (b <= 100000) p = 100000;
            else if (b < 1000000) p = 1000000;
            else p = 10000000;
            ans = min(ans, nums[i] * p + b);
        }
        return ans;
    }
};