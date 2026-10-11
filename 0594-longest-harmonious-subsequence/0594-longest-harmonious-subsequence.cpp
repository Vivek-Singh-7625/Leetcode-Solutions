class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int l = 0 , r = 0 , ans = 0 , t;
        while(r < n) {
            while (r < n && nums[r]-nums[l] <= 1) {
                r++;
            }
            if (nums[r-1]-nums[l]==1) ans = max(ans, r-l);
            t = nums[l];
            while (l < r && t == nums[l]) {
                l++;
            }
        }
        return ans;
    }
};