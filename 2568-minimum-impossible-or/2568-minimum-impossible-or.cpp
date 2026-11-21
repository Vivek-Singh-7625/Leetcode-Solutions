class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ans = 0;
        for (auto &n : nums) {
            if ((n & (n-1)) == 0) ans |= n;  // no. is power of 2
        }
        ans = ~ans; // to get first bit lsb which is set to 0
        return (ans & (-ans));  // isolates the lowest set bit (the rightmost 1 in binary)
    }
};