class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)    nums[i] *= nums[i];
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n/2 ; i++){
            ans += nums[n-i-1];
            ans -= nums[i];
        }
        if(n%2) ans += nums[n/2];
        return ans;
    }
};