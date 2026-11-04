class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0 , m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j])  ans = max(ans , solver(grid , i , j));
            }
        }
        return ans;
    }
    int solver(vector<vector<int>>& grid , int x , int y){
        int m = grid.size() , n = grid[0].size();
        if(x < 0 or y < 0 or x >= m or y >= n)  return 0;
        int t = grid[x][y] , ans = 0;
        if(t == 0)  return 0;
        vector<int> r(4) , c(4);
        r[0] = 1 , r[1] = -1;
        c[2] = 1 , c[3] = -1;
        for(int i = 0 ; i < 4 ; i++){
            grid[x][y] = 0;
            ans = max(ans,t + solver(grid , x + r[i] , y + c[i]));
            grid[x][y] = t;
        }
        return ans;
    }
};