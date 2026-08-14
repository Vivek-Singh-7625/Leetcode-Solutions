class Solution {
public:
    int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long y = 1;
        y = (1ll*myPow(4,n/2)*myPow(5,n-n/2))%MOD;
        return y;
    }
    int myPow(int x, long long n) {
        if(n == 0)  return 1;
        if(n == 1)  return x;
        int t = myPow(x,abs(n/2));
        if(n%2) return (1ll*t*t*x)%MOD;
        return (1ll*t*t)%MOD;
    }
};