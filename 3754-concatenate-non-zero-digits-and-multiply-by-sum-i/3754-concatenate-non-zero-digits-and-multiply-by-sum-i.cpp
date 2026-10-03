class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0 , t = 1;
        int sum = 0 , p ;
        while(t*10 <= n) t = t*10;
        while(n){
            p = n/t;
            if(p)    ans = ans*10 + p; 
            sum += p;
            n = n%t;
            t = t/10;
        }
        return ans*sum;
    }
};