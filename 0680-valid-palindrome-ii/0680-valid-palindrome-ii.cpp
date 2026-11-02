class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1, n;

        while(start < end){
            if(s[start] == s[end])  start++, end--;
            else    break;
        }

        if(end <= start)    return true;

        string a, b;
        a = s.substr(start, end - start);
        b = s.substr(start + 1, end - start);

        bool ans1 = true, ans2 = true;
        n = a.length();

        for(int i = 0; i < n/2; i++){
            if(a[i] != a[n-1-i])    ans1 = false;
            if(b[i] != b[n-1-i])    ans2 = false;
        }
        return ans1 or ans2;
    }
};