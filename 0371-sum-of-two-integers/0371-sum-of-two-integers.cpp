class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0 , val , t , x , y;
        for(int i = 0 ; i < 32 ; i++){
            t = (1 << i);
            x = (a&t);
            y = (b&t);
            val = (x^y)^(carry);
            if(val) ans = (ans | t);
            carry = (x&y | x&carry | y&carry) << 1;
        }
        return ans;
    }
};