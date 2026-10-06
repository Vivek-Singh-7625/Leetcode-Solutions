class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length() , mn = 0 , mx = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') mn++ , mx++;
            else if(s[i] == ')')    mx-- , mn--;
            else    mn-- , mx++;
            if(mn < 0)  mn = 0;
            if(mx < 0)  return false;
        }
        return mn == 0;
    }
};