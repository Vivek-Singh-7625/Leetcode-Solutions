class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0 , n = s.length() , t = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') t++;
            else{
                t--;
                if(s[i-1] == '(')   ans += (1 << t);
            }
        }
        return ans;
    }
};