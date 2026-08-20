class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int t = 0 , sum = 0 , ans = 0;
        vector<int> mpp(n+1);
        mpp[0] = 1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(sum >= goal and mpp[sum - goal]) ans += mpp[sum-goal];
            mpp[sum]++;
        }
        return ans;
    }
};