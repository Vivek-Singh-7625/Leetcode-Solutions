class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long target = 0, mx = 0;
        for(int x : matchsticks) {
            target += x;
            mx = max(mx, 1LL * x);
        }
        if(target % 4 || mx > target / 4)   return false;
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        return solver(matchsticks, 0, 0, 0, 0, 0, target / 4);
    }

    bool solver(vector<int>& m, long long a, long long b, long long c, long long d, int idx, long long target) {

        if(a > target || b > target || c > target || d > target)    return false;
        if(idx == m.size()) return true;

        int x = m[idx];

        if(a != b && solver(m, a+x, b, c, d, idx+1, target))    return true;
        if(b != c && solver(m, a, b+x, c, d, idx+1, target))    return true;
        if(c != d && solver(m, a, b, c+x, d, idx+1, target))    return true;
        if(solver(m, a, b, c, d+x, idx+1, target))  return true;
        return false;
    }
};