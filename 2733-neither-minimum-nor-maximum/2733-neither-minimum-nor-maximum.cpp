class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)  return -1;
        int mx = max(nums[0],max(nums[1],nums[2]));
        int mn = min(nums[0],min(nums[1],nums[2]));
        if(nums[0] == mx || nums[0] == mn){
            if(nums[1] == mx || nums[1] == mn)  return nums[2];
            else    return  nums[1];
        }
        return nums[0];
    }
};