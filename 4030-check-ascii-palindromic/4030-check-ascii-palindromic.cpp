class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.length() , t = 255 , x , y;
        string a ,b;
        for(int i = 0 ; i < n/2 + n%2 ; i++){
            x = s[i];
            y = s[n-i-1];
            a = bitset<8>(x).to_string();
            b = bitset<8>(y).to_string();
            reverse(b.begin(),b.end());
            if(a != b)  return false;
        }
        return true;
    }
};