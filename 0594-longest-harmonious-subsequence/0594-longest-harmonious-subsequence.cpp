class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int x : nums)   mpp[x]++;
        int ans = 0;
        for(auto [k, v] : mpp) {
            auto it = mpp.find(k + 1);
            if(it != mpp.end()) {
                ans = max(ans, v + it->second);
            }
        }
        return ans;
    }
};