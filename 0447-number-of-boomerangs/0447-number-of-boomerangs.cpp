class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size() , x , y , ans = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_map<int,int> mpp;
            for(int j = 0 ; j < n ; j++){
                if(i == j)  continue;
                x = points[i][0]-points[j][0];
                y = points[i][1]-points[j][1];
                mpp[x*x + y*y]++;
            }
            for(auto& [key,val] : mpp)  ans += val*(val-1);
        }
        return ans;
    }
};