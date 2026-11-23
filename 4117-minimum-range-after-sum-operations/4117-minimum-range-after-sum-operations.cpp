class Solution {
public:
    int minRange(int a, int b, int c) {
        int x = min({a,b,c});
        int y = max({a,b,c});
        int z = max({min(a,b),min(b,c),min(a,c)});
        return min(y - x,z);
    }
};