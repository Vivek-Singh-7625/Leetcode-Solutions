class Solution {
public:
    string countAndSay(int n) {
        int count = 0;
        string s = "1" , t;
        char x;
        for(int i = 1 ; i < n ; i++){
            x = s[0];
            count = 0;
            t = "";
            for(int j = 0 ; j < s.length() ; j++){
                if(x == s[j])   count++;
                else{
                    t += to_string(count) + x;
                    x = s[j];
                    count = 1;
                }
            }
            t += to_string(count) + x;
            s = t;
        }
        return s;
    }
};