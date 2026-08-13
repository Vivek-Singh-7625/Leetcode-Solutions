class Solution {
public:
    int maxDepth(string s) {
        int l = 0 , r = 0 , ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') l++;
            else if(s[i] == ')')    r++;
            ans = max(l-r,ans);
        }
        return ans;
    }
};