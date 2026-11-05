class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() , n = grid[0].size();
        int p = m*n;
        vector<int> temp(p);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                temp[i*n+j] = grid[i][j];
                cout << i*n + j << endl;
            }
        }
        sort(temp.begin(),temp.end());
        int a , b , c , ans1 = 0 , ans2 = 0;
        if(p&1) a = temp[p/2] , b = temp[p/2];
        else    a = temp[p/2] , b = temp[p/2 - 1];
        bool a1 = true , b1 = true;
        for(int y : temp){
            c = abs(y-a);
            if(a1 and c%x == 0)  ans1 += c/x;
            else    a1 = false;
            c = abs(y-b);
            if(b1 and c%x == 0)  ans2 += c/x;
            else    b1 = false;
        }
        int ans = -1;
        if(a1)  ans = ans1;
        if(b1){
            ans = ans2;
            if(a1)  ans  = min(ans1,ans);
        }
        return ans;
    }
};