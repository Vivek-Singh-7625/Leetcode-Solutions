class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mpp;
        int n = groupSizes.size() , x , y , k;
        for(int i = 0 ; i < n ; i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto [key,value] : mpp){
            n = mpp[key].size();
            y = (n-1)/key + 1;
            x = key;
            k = 0;
            vector<int> temp;
            for (int val : mpp[key]) {
                if(k++ < x) temp.push_back(val);
                else{
                    ans.push_back(temp);
                    temp.clear();
                    temp.push_back(val);
                    k = 1;
                }
            }
            if(k)   ans.push_back(temp);
        }
        return ans;
    }
};