class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , product = 1 , t , x = n;
        while(n){
            t = n%10;
            sum += t;
            product *= t;
            n = n/10;
        }
        return x%(sum+product) == 0;
    }
};