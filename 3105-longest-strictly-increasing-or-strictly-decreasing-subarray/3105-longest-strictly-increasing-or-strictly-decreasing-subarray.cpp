class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si = 1 , sd = 1 , ans = 1;
        for(int i = 1 ; i < nums.size() ; i++) {
            si = nums[i] > nums[i-1] ? si+1 : 1;
            sd = nums[i] < nums[i-1] ? sd+1 : 1;
            ans = max(ans,max(si,sd));
        }
        return ans;
    }
};