class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1 , b = -1 , c = -1;
        int n = s.length() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            ans += min(a,min(b,c)) + 1;
        }
        return ans;
    }
};