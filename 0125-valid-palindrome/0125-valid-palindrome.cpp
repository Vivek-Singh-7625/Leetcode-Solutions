class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string temp ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' and s[i] <= 'z'){
                temp += s[i];
            }
            else if(s[i] >= 'A' and s[i] <= 'Z'){
                temp += (s[i] - 'A' + 'a');
            }
            else if(s[i] >= '0' and s[i] <= '9'){
                temp += s[i];
            }
        }
        n = temp.length();
        for(int i = 0 ; i < n/2 ; i++){
            if(temp[i] != temp[n-i-1])    return false;
        }
        return true;
    }
};