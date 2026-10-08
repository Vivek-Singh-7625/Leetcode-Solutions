class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            if (mpp.count(sum)) {
                if (i + 1 - mpp[sum] >= 2)  return true;
            } 
            else {
                mpp[sum] = i + 1;
            }
        }
        return false;
    }
};