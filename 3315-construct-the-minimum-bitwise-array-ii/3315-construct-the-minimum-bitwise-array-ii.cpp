class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() , k;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 2)    nums[i] = -1;
            else{
                k = nums[i] + 1;
                nums[i] = (nums[i]^((-k & k) >> 1));
            }
        }
        return nums;
    }
};