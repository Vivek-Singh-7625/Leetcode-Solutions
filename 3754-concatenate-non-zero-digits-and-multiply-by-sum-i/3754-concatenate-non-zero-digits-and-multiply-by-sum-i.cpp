class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string s = to_string(n);
        long long ans = 0;
        int sum = 0 , d;
        for (char c : s) {
            if (c != '0') {
                d = c - '0';
                ans = ans * 10 + d;
                sum += d;
            }
        }
        return ans * sum;
    }
};