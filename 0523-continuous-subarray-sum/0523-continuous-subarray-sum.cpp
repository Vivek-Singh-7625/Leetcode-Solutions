class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size() , sum = 0;
        mpp[0] = 0;
        for(int i = 0 ; i < n ; i++){
            sum = (sum + nums[i])%k; 
            if(mpp.find(sum) != mpp.end() and i + 1 - mpp[sum] >= 2)   return true;
            if(mpp[sum] == 0 and sum)   mpp[sum] = i+1;
        }
        return false;
    }
};