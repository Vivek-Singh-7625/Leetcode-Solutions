class Solution {
public:
    bool isequal(string &s, int a, int b) {
        while(a < b){
            if(s[a] != s[b])    return false;
            a++, b--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end){
            if(s[start] == s[end])  start++, end--;
            else    return isequal(s, start + 1, end) || isequal(s, start, end - 1);
        }
        return true;
    }
};