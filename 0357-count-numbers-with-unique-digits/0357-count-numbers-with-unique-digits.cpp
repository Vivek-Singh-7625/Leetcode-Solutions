class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n)  return 1;
        int c = 9 ,  p = 1 , k = 9; 
        for(int i = 1 ; i <= n ; i++ ){  
           p += c;
           c = c*k;
           k--;
        }
        return p;
    }
};