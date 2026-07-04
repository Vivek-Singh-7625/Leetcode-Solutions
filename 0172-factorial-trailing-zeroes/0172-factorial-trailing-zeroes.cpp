class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0 , temp;
        long long p5 = 0;
        for(int i = 1 ; i <= n ; i++){
            temp = i;
            while(temp%5 == 0){
                temp = temp/5;
                p5++;
            }
        }
        return p5;
    }
};