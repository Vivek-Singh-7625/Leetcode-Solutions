class Solution {
public:
    int minRotations(string s) {
        int ans = 0 , p = 0 , r;
        for(char c : s){
            r = c-'0';
            p = min(abs(r-p),10-abs(r-p));
            ans += p;
            p = r;
        }
        return ans;
    }
};