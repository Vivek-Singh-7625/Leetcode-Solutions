class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) ans += closed(grid , i , j);
            }
        }
        return ans;
    }
    bool closed(vector<vector<int>>& visited , int i , int j){
        if(i < 0 or  j < 0 or  i >= visited.size() or j >= visited[0].size())  return false;
        if(visited[i][j])   return true;
        visited[i][j] = 1;
        return closed(visited,i-1,j)&closed(visited,i+1,j)&closed(visited,i,j+1)&closed(visited,i,j-1);
    }
};