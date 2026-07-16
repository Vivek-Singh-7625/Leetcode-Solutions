class Solution {
public:
    int myAtoi(string s) {
        bool isSpace = true , isSign = true ;
        int num = 0 , sign = 1 , n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ' ' && isSpace) continue;
            else if((s[i] == '+' || s[i] == '-') && isSign){
                isSign = false;
                isSpace = false;
                if(s[i] == '-') sign = -1; 
            }
            else if(s[i] >= '0' and s[i] <= '9'){
                isSign = false;
                isSpace = false;
                if (num > INT_MAX / 10)
                    return sign == 1 ? INT_MAX : INT_MIN;
                else if (num == INT_MAX / 10 && s[i] - '0' > 7)
                    return sign == 1 ? INT_MAX : INT_MIN;
                else
                    num = num * 10 + (s[i] - '0');
            }
            else return sign*num;
        }
        return sign*num;
    }
};