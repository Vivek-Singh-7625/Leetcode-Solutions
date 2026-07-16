class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int x = 0 ;
        for(int i = 0 ; i < k ; i++){
            x += nums[n-1-i];
            x -= nums[i];
        }
        return x;
    }
};