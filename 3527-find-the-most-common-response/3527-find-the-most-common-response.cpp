class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mpp;
        mpp.reserve(responses.size() * 10);

        for (int i = 0; i < responses.size(); i++) {
            unordered_map<string, int> mp;
            mp.reserve(responses[i].size());
            for (int j = 0; j < responses[i].size(); j++)   mp[responses[i][j]]++;
            for (auto &[k, v] : mp) mpp[k]++;
        }

        string ans = "";
        int t = -1;
        for (auto &[k, v] : mpp) {
            if (v > t || (v == t && k < ans)) {
                ans = k;
                t = v;
            }
        }
        return ans;
    }
};