class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int x = 0 , y = 1e9, z = 1e9 , ans = 0;
        for(int i = 1 ; i <= n ; i++){
            ans = min({x + 1,y + 4,z + 9});
            z = y;
            y = x;
            x = costs[i-1] + ans;
        }
        return x;
    }
};