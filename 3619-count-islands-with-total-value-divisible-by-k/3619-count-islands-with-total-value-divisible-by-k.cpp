class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0 , m = grid.size() , n = grid[0].size() , t;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){
                    t = floodfill(grid,i,j,k);
                    if(t%k == 0)    ans++;
                }
            }
        }
        return ans;
    }
    int floodfill(vector<vector<int>>& grid , int i , int j , int k){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())   return 0;
        if(!grid[i][j]) return 0;
        int x = grid[i][j];
        grid[i][j] = 0;
        return x + floodfill(grid,i+1,j,k)%k + floodfill(grid,i-1,j,k)%k + floodfill(grid,i,j+1,k)%k + floodfill(grid,i,j-1,k)%k;
    }
};