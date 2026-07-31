class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>    mpp;
        for(int i = 0 ; i < paths.size() ; i++){
            mpp[paths[i][0]] =  paths[i][1]; 
        }
        string ans = paths[0][0];
        while(mpp[ans] != "")   ans = mpp[ans];
        return ans;
    }
};