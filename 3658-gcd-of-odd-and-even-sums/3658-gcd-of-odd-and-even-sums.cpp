class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x , y;
        y = n*(n+1);
        x = 2*n*(2*n + 1)/2 - y;
        return gcd(x,y);
    }
};