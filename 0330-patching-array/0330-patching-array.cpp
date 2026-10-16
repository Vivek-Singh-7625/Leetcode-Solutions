class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0 , i = 0 , s = nums.size();
        long long range = 0 ;
        while(range < n){
            if(i < s and nums[i] <= range + 1){
                range += nums[i];
                i++;
            }
            else{    
                range += (range + 1);
                ans++;
            }
        }
        return ans;
    }
};