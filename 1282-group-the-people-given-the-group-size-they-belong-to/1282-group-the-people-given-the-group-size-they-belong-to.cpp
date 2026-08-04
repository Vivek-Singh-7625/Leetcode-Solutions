class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mpp;
        int n = groupSizes.size() , x , y , k;
        for(int i = 0 ; i < n ; i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& [key,value] : mpp){
            n = value.size();
            x = key;
            k = 0;
            vector<int> temp;
            for (int val : mpp[key]) {
                temp.push_back(val);
                if (temp.size() == key) {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
            if(temp.size())   ans.push_back(temp);
        }
        return ans;
    }
};