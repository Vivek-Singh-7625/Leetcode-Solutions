class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> A(26,0);
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            A[s[i]-'a']++;
        }
        int idx = -1;
        string p;
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < A[i]/2 ; j++)   p += ('a' + i);
            if(A[i]%2)  idx = i;
        }
        string p2 = p;
        reverse(p2.begin() , p2.end());
        char x = ('a' + idx);
        if(idx != -1)   return p + x + p2;
        return p + p2;
    }
};