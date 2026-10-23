class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX , mx = 0 , idx = 0 , n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++)    mpp[nums[i]] = i;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i){  
                ans = ans & nums[i];
            }
        }
        if(ans == INT_MAX)  return 0;
        return ans;
    }
};