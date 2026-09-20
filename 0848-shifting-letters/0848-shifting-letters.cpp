class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length() , k = 0;
        char t;
        for(int i = n-1 ; i >= 0 ; i--){
            k += (shifts[i])%26;
            t = (k + s[i] - 'a')%26 + 'a';
            s[i] = t;
        }
        return s;
    }
};