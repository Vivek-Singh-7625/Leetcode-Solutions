class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        int k = 0;
        unsigned long long a = 1;
        while(a*1000 <= n){
            ans += (k*(a*1000 - a));
            a = a*1000;
            k++;
        }
        if(n >= a)  ans += k*(n-a+1);
        return ans;
    }
};