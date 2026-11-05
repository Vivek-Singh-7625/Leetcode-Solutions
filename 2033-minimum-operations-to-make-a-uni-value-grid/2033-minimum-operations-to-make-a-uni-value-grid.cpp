class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int p = m * n , c , r = grid[0][0]%x;

        vector<int> temp(p);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                c = grid[i][j];
                if(c%x != r)   return -1;
                temp[i*n+j] = c;
            }
        }

        sort(temp.begin(), temp.end());
        int a = temp[p/2];

        int ans = 0;
        bool a1 = true;
        for(int y : temp){
            c = abs(y-a);
            if(c % x == 0)  ans += c/x;
            else    a1 = false;
        }
        if(a1)  return ans;
        return -1;
    }
};