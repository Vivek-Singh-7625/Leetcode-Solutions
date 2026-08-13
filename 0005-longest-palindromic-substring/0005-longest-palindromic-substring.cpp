class Solution {
public:
    string longestPalindrome(string s) {
        string t ;
        t += "#";
        int n = s.length() , max_len = 0 , sp = 0;
        for(int i = 0 ; i < n ; i++){
            t += s[i];
            t += '#';
        }
        vector<int> p(2*n+1);
        int center = 0 , right = 0 , mirror ;
        for(int i = 0 ; i < 2*n + 1; i++){
            mirror = 2*center-i;
            if(i < right){
                p[i] = min(p[mirror],right-i);
            }
            while(i-p[i]-1 >= 0 and i + p[i] + 1 < 2*n+1 and t[i-p[i]-1] == t[i+p[i]+1])    p[i]++;
            if(i + p[i] > right){
                right = i + p[i];
                center = i;
            }
            if(p[i] > max_len){
                max_len = p[i];
                sp = (i - max_len)/2;
            }
        }
        return s.substr(sp,max_len);
    }
};