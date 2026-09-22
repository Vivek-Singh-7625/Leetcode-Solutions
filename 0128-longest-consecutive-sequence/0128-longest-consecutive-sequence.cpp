class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() , v , curr;
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto& val : s) {
            if (s.contains(val - 1))    continue;
            v = val;
            curr = 1;
            while (s.contains(v + 1)) {
                curr++;
                v++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};