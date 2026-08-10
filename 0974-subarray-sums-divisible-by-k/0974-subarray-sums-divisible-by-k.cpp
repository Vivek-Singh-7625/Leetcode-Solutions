class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0 , p = 0 ;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            p += nums[i];
            ans += mpp[(p%k+k)%k];
            mpp[(p%k+k)%k]++;
        }
        ans += mpp[0];
        return ans;
    }
};