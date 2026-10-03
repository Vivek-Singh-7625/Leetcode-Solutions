class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0 , a , b;
        long long key;
        unordered_map<long long, int> mp;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                pairs++;
            } 
            else {
                a = nums[i - 1];
                b = nums[i];
                if (a > b) swap(a, b);
                key = 1ll*a*(1e9+1) + b;
                mp[key]++;
            }
        }
        int ans = 0;
        for (auto& [k,v] : mp) {
            ans = max(ans, v);
        }
        return pairs + ans;
   }
};