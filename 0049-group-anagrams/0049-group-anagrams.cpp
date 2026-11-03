class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string t;
        int n = strs.size() , idx = 1;
        vector<vector<string>> ans;
        unordered_map<string,int> mpp;
        for(int i = 0 ; i < n ; i++){
            t = strs[i];
            sort(t.begin(),t.end());
            if(mpp[t] == 0){
                mpp[t] = idx++;
                ans.push_back({strs[i]});
            }
            else    ans[mpp[t]-1].push_back(strs[i]);
        }
        return ans;
    }
};