class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0 , sp = 0 , len;
        for(int i = 0; i < s.length() ; i++){
            len = 0;
            for(int j = i ; j < s.length() ; j++){
                len++;
                if(s.length()-i < max_len)   break;
                if(solve(i,j,s) == true){
                    if(max_len < len){
                        max_len = len;
                        sp = i;
                    }
                }  
            }
        }
        return s.substr(sp,max_len);
    }
    bool solve(int& x , int& y , string& s){
        int len = y - x + 1;
        for(int i = 0 ; i < len/2 ; i++){
            if(s[x+i] != s[y-i])    return false;
        }
        return true;
    }
};