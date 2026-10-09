class Solution {
public:
    int minInsertions(string s) {
        int n = s.length() , t = 0 , ans  = 0 ;
        for(char c : s){
            if(c == '('){ 
                if(t%2)   t-- , ans++;
                t += 2;
            }
            else{
                if(t == 0)  t++ , ans ++;
                else    t--;
            }
        }
        if(t >= 0)  ans += t;
        return ans;
    }
};