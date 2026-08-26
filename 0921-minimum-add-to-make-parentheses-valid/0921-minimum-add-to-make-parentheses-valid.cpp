class Solution {
public:
    int minAddToMakeValid(string s) {
        int a = 0 , n = s.length() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') a++;
            else    a--;
            if(a < 0){
                ans++;
                a = 0;
            }
        }
        return ans + abs(a);
    }
};