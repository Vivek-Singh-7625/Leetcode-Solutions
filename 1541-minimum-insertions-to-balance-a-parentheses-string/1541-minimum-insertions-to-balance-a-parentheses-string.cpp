class Solution {
public:
    int minInsertions(string s) {
        int n = s.length() , t = 0 , ans  = 0 ;
        for(char c : s){
            if(c == '('){ 
                if(t < 0)   t = 0;
                if(t%2)   t-- , ans++;
                t += 2;
            }
            else{
                t--;
                if(t < 0){
                    ans = (-t)%2 ? ans + 2 : ans - 1;
                }
            }
        }
        if(t >= 0)  ans += t;
        return ans;
    }
};