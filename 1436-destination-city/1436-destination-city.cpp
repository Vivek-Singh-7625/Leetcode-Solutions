class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ans;
        int n = paths.size();
        for(int i=0;i<n;i++){
            ans.insert(paths[i][1]); 
        }
        for(int i=0;i<n;i++){
            ans.erase(paths[i][0]); 
        }
        return *ans.begin();
    }
};