class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int l = 0 , r = 0 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') l++;
            else    r++;
            if(l == r)  ans = max(ans,l*2);
            if(r > l)   l = 0 , r = 0;
        }
        l = 0 , r = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '(') l++;
            else    r++;
            if(l == r)  ans = max(ans,l*2);
            if(l > r)   l = 0 , r = 0;
        }
        return ans;
    }
};