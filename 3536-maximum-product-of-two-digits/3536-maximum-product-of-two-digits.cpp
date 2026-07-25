class Solution {
public:
    int maxProduct(int n) {
        int digit1 = -1 , digit2 = -1 , digit;
        while(n){
            digit = n%10;
            n = n/10;
            if(digit1 < digit){  
                digit2 = digit1;
                digit1 = digit;
            }
            else if(digit2 < digit) digit2 = digit;
        }
        return digit1*digit2;;
    }
};