class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0 , g;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                g = gcd(nums[i],nums[j]);
                ans = max((1LL*nums[i]*nums[j])/(g*g),ans);
            }
        }
        return ans;
    }
};