class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length() , mn = 0 , mx = 0 , t = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') mn++ , mx++;
            else if(s[i] == ')'){    
                mn--;
                if(mx > 0 and mn < 0)   mn = 0;
                mx-- ;
            }
            else{
                mn--;
                if(mn < 0)  mn = 0;
                mx++;
            }
            if(mx < 0 and mn < 0)   return false;
        }
        return mn == 0;
    }
};