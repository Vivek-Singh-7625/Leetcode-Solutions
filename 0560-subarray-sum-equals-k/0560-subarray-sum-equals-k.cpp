class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() , val = 0 , ans = 0;
        unordered_map<int,int> mpp;
        mpp.reserve(2*n);
        mpp[val]++;
        for(int i = 0 ; i < n ; i++){
            val += nums[i];
            ans += mpp[val-k];
            mpp[val]++;
        }
        return ans;
    }
};