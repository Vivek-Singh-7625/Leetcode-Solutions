class Solution {
public:
    int minInsertions(string s) {
        int n = s.length() , t = 0 , ans  = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){ 
                if(t < 0)   t = 0;
                if(t%2 and s[i-1] == ')')   t-- , ans++;
                t += 2;
            }
            else{
                t--;
                if(t < 0){
                    if((-t)%2)  ans += 2;
                    else    ans--;
                }
            }
        }
        if(t >= 0)  ans += t;
        return ans;
    }
};