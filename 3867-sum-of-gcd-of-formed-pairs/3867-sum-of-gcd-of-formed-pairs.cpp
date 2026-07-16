class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mxi = INT_MIN , n = nums.size();
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){    
            mxi = max(nums[i],mxi);
            nums[i] = gcd(mxi,nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n/2 ; i++)  ans += gcd(nums[i],nums[n-1-i]);
        return ans;
    }
};