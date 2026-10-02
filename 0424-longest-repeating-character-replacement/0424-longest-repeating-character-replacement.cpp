class Solution {
public:
    int characterReplacement(string s, int k) {
        int st = 0, ans = 0, maxFreq = 0;
        unordered_map<int, int> mpp;
        mpp.reserve(26);
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
            maxFreq = max(maxFreq, mpp[s[i]]);
            while ((i - st + 1) - maxFreq > k) {
                mpp[s[st]]--;
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};