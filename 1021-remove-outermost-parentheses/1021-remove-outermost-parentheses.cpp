class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = 0 , r = 0 ;
        string ans;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                l++;
            }
            if(s[i] == ')'){
                r++;
            }
            if(l-r != 1 and s[i] == '(')  ans += s[i];
            if((l - r != 0) and s[i] == ')')  ans += s[i];
        }
        return ans;
    }
};