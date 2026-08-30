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
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        int m = grid.size() , n = grid[0].size();
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int a = x.first , b = x.second;
            if(a < m-1 and grid[a+1][b] == '1'){ 
                q.push({a+1,b});
                grid[a+1][b] = '0';
            }
            if(b < n-1 and grid[a][b+1] == '1'){ 
                q.push({a,b+1});
                grid[a][b+1] = '0';
            }
            if(a  and grid[a-1][b] == '1'){ 
                q.push({a-1,b});
                grid[a-1][b] = '0';
            }
            if(b  and grid[a][b-1] == '1'){ 
                q.push({a,b-1});
                grid[a][b-1] = '0';
            }
        }
    }
};