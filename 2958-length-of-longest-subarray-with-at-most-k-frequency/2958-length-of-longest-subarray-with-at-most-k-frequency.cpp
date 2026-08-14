class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int l = 0 , r = 1 , t , ans = 1;
        mpp[nums[0]]++;
        while(l <= r and r < n){
            t = nums[r++];
            mpp[t]++;
            while(mpp[t] > k){
                mpp[nums[l++]]--;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};