class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size() , ans = 0;
        bool above = false , left = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){   
                    ans++;
                    solver(grid,i,j);
                }
            }
        }
        return ans;
    }
    void solver(vector<vector<char>>& grid , int i , int j){
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        if(i > 0)   solver(grid, i - 1, j);
        if(i < grid.size() - 1) solver(grid, i + 1, j);
        if(j > 0)   solver(grid, i, j - 1);
        if(j < grid[0].size() - 1)  solver(grid, i, j + 1);
    }
};