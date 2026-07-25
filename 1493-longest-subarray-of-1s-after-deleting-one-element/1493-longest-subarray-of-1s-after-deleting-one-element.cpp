class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() , st = 0 , cz = 0 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0)   cz++; 
            if(cz > 1){
                while(st < n-1 and nums[st++] != 0);
                cz--;
            }
            ans = max(ans,i-st);
        }
        return ans;
    }
};