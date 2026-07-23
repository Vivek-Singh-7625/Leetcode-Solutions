class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        for(int i = 1 ; i < n ; i++){
            nums[i] += nums[i-1];
        }
        int start = 0;
        for(int i = 0 ; i < n ; i++){
            while(i+1 - nums[i] - start + (start > 0 ? nums[start-1] : 0) > k){
                start++;
            }
            ans = max(ans,i+1-start);
        }
        return ans;
    }
};