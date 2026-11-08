class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , t , ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){
                    t = dfs(grid , i , j);
                    if(t > 1)   ans += t;
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& g  , int x , int y){
        int m = g.size() , n = g[0].size();
        if(x < 0 or y < 0 or x >= m or y >= n)  return 0;
        if(g[x][y] == 0)    return 0;
        g[x][y] = 0;
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            ans += dfs(g,i,y);
        }
        for(int i = 0 ; i < n ; i++){
            ans += dfs(g,x,i);
        }
        return ans + 1;
    }
};