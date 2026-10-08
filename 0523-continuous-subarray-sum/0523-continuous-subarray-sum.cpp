class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size() , sum = 0;
        if(n == 1)  return false;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%k == 0){
                mpp[0]++;
                if(mpp[0] > 1)    return true;
                continue;
            }
            else    mpp[0] = 0;
            sum += nums[i];
            mpp[sum%k]++ ;
            if(mpp[sum%k] > 1 or mpp[0])    return true;
        }
        return false;
    }
};