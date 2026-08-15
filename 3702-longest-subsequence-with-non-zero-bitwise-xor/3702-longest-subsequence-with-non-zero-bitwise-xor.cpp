class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() , val = 0;
        bool isZero = true;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0)    isZero = false;
            val = val^nums[i];
        }
        if(isZero)  return 0;
        if(val) return n;
        return n-1;
    }
};