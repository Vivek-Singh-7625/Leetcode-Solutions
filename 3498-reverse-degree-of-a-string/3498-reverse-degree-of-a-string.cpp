class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0 , k = 1;
        for(char& x : s)    ans += (k++)*('z'-x+1);
        return ans;
    }
};