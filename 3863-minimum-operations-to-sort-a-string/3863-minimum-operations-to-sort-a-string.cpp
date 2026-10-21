class Solution {
public:
    int minOperations(string s) {
        int n = s.length() , ans = 0;
        if(n <= 2){
            if(n == 1)  return 0;
            return s[0] > s[1] ? -1 : 0;
        }
        string a = s.substr(0,n-1) , b = s.substr(1) , c = s;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        if(s == c)  return 0;
        else if((a + s[n-1]) == c or (s[0] + b) == c)  return 1;
        else if(s[0] == c[n-1] and s[n-1] == c[0] and c[0] != c[1] and c[n-1] != c[n-2])  return 3;
        return 2;
    }
};