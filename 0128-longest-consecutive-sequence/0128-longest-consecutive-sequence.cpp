class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return 1;
        int k = 1 , ans = 1;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i] + 1 == nums[i+1] or nums[i] == nums[i+1]){
                if(nums[i] + 1 == nums[i+1])
                    k++;
            }
            else{
                ans = max(ans,k);
                k = 1;
            }
        }
        ans = max(ans,k);
        return ans;
    }
};