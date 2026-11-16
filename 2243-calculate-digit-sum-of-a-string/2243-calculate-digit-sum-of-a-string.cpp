class Solution {
public:
    string digitSum(string s, int k) {
        string t;
        int n , y;
        while(s.length() > k){
            n = s.length() , y = 0;
            for(int i = 0 ; i < n ; i++){
                if(i%k){
                    y += (s[i] - '0');
                }
                else{
                    if(i)   t += to_string(y);
                    y = (s[i] - '0');
                }
            }
            t += to_string(y);
            s = t;
            t = "";
        }
        return s;
    }
};