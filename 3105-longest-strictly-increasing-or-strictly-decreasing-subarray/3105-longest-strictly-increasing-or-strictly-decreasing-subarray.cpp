class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si = 0 , sd = 0 , ans = 0 , n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i-1]){
                ans = max(ans,sd);
                si++;
                sd = 0;
            }
            else if(nums[i] < nums[i-1]){
                ans = max(ans,si);
                sd++;
                si = 0;
            }
            else{
                ans = max(ans,max(si,sd));
                si = 0 , sd = 0;
            }
        }
        return max(ans,max(si,sd)) + 1;
    }
};