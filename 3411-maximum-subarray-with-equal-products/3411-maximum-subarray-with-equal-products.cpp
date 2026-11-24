class Solution {
public:
    int maxLength(vector<int>& nums) {
        int prod = 1 , GCD , LCM , ans = 1 , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            prod = nums[i] , GCD = nums[i] , LCM = nums[i];
            for(int j = i + 1 ; j < n ; j++){
                prod = prod*nums[j];
                GCD = gcd(nums[j],GCD);
                LCM = lcm(nums[j],LCM);
                if(prod == GCD * LCM)   ans = max(j - i + 1 , ans);
                if(prod > INT_MAX/100000)   break;
            }
        }
        return ans;
    }
};