class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int x = 0 , y = 0 , n = s.length() , ones = 0 , ans = INT_MAX , idx = 0;
        while(y < n){
            if(s[y] == '1')  ones++;
            y++;
            while(ones > k){
                if(s[x++] == '1')  ones--;
            }
            while(s[x] == '0'){
                x++;
            }
            if(ones == k){   
                if (y - x < ans || (y - x == ans && s.compare(x, y-x, s, idx, y-x) < 0)) {
                    ans = y-x;
                    idx = x;
                }
            }
        }
        if(ans == INT_MAX)  return "";
        return s.substr(idx,ans);
    }
};