class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int m = responses.size() , t = -1;
        unordered_map<string,int> mpp;
        for(int i = 0 ; i < m ; i++){
            unordered_map<string,int> mp;
            mp.reserve(responses[i].size());
            for(int j = 0 ; j < responses[i].size() ; j++)  mp[responses[i][j]]++;
            for(auto [k,v] : mp)    mpp[k]++;
        }
        string ans = "zzzzzzzzzzzzzzzzzzzz";
        for(auto [k,v] : mpp){
            if (v > t) {
                ans = k;
                t = v;
            } 
            else if (v == t) {
                if (k < ans)    ans = k;
            }
        }
        return ans;
    }
};