class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string temp = s.substr(0,n/2);
        sort(temp.begin(),temp.end());
        string temp2 = temp;
        reverse(temp2.begin(),temp2.end());
        if(n%2) return temp + s[n/2] + temp2;
        return temp + temp2;
    }
};