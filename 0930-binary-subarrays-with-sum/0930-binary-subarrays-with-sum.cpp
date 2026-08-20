class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int t = 0 , sum = 0 , ans = 0;
        for(int i = 1 ; i < n ; i++)    nums[i] += nums[i-1];
        if(nums[n-1] < goal)    return 0;
        if(nums[n-1] == 0){
            if(goal == 0)  return n*(n+1)/2;
            else    return 0;
        }  
        for(int i = 0 ; i < n ; i++){
            t = i == 0 ? 0 : nums[i-1];
            for(int j = i ; j < n ; j++)   if(nums[j]-t == goal) ans++;
        }
        return ans;
    }
};