class Solution {
public:
    int minRotations(string s) {
        int curr = 0 , n , ans = 0 , d;
        for(char c : s){
            n = c - '0';
            d = abs(n - curr);
            ans += min(d , 10 - d);
            curr = n;
        }
        return ans;
    }
};