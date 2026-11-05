class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int p = m * n;

        vector<int> temp(p);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                temp[i*n+j] = grid[i][j];
            }
        }

        sort(temp.begin(), temp.end());
        int a = temp[p/2];
        int b = temp[(p-1)/2];

        int ans1 = 0, ans2 = 0 , c;
        bool a1 = true, b1 = true;

        for(int y : temp){
            c = abs(y-a);

            if(c % x == 0)  ans1 += c/x;
            else    a1 = false;

            c = abs(y-b);

            if(c % x == 0)  ans2 += c/x;
            else    b1 = false;
        }
        
        if(a1 and b1)   return min(ans1, ans2);
        if(a1)           return ans1;
        if(b1)           return ans2;
        return -1;
    }
};