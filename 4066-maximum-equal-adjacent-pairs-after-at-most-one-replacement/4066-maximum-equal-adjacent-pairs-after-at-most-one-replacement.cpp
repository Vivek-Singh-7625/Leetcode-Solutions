class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size() , a = 0 , b = 0 , p = 0 , ans = 0;
        unordered_map<long long,int> mpp;
        for(int i = 1 ; i < n ; i++){
            a = min(nums[i],nums[i-1]);
            b = max(nums[i],nums[i-1]);
            if(a == b) p++;
            mpp[1ll*a*(1e9+1) + b]++;
        }
        for(int i = 1 ; i < n ; i++){
            a = min(nums[i],nums[i-1]);
            b = max(nums[i],nums[i-1]);
            if(a != b)  ans = max(ans,mpp[1ll*a*(1e9+1) + b] + p);
            else    ans = max(ans,mpp[1ll*a*(1e9+1) + b]);
        }
        return ans;
    }
};