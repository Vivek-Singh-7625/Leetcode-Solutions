class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> C(128, -1);
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (C[s[i]] >= l)   l = C[s[i]] + 1;
            C[s[i]] = i;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};