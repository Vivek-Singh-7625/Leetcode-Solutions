class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.length() , t , x;
        for(int i = 0 ; i < n ; i++){
            if(k == 0)  break;
            x = s[i] - 'a';
            t = min(k , min(x,26-x));
            if(k > min(x,26-x)) s[i] -= x;
            else    s[i] = min(s[i] - k,'a' + (k+x)%26);
            k -= t;
        }
        return s;
    }
};