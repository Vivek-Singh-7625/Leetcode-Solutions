class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        mpp.reserve(m*n);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                mpp[grid[i][j]]++;
                if(mpp[grid[i][j]] > 1){
                    ans.push_back(grid[i][j]);
                    mpp[grid[i][j]] = -m*n;
                }
            }
        }
        for(int i = 1 ; i <= m*n ; i++){
            if(mpp[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};