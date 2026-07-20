class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() , x = 0;
        k = k%(m * n);
        vector<int> t;
        stack<int> A;
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(x < k){
                    x++;
                    t.push_back(grid[i][j]);
                }
                A.push(grid[i][j]);
            }
        }
        int y = t.size();
        x = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(x++ < k)   grid[i][j] = t[--y];
                else{    
                    grid[i][j] = A.top();
                    A.pop();
                }
            }
        }
        return grid;
    }
};