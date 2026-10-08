class Solution {
public:
    string removeOuterParentheses(string s) {
        int t = 0;
        string ans = "";
        for (char ch : s) {
            if (ch == '(') {
                if (t > 0) ans += '(';
                t++;
            }
            else {
                t--;
                if (t > 0) ans += ')';
            }
        }
        return ans;
    }
};