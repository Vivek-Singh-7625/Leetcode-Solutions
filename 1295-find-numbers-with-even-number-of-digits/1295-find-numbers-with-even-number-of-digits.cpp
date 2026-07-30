class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= 10 and nums[i] <= 99)  ans++;
            else if(nums[i] >= 1000 and nums[i] <= 9999)  ans++;
            else if(nums[i] >= 100000 and nums[i] <= 999999)  ans++;
            else if(nums[i] >= 10000000 and nums[i] <= 99999999)  ans++;
        }
        return ans;
    }
};