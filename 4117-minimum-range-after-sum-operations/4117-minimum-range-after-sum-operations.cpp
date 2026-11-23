class Solution {
public:
    int minRange(int a, int b, int c) {
        int x = min({a,b,c}) , y = max({a,b,c}) , z = min({max(a,b),max(b,c),max(a,c)});
        if(x + z < y)   y = x + z;
        return max(y,z) - x;
    }
};