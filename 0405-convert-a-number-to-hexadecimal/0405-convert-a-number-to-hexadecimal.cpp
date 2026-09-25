class Solution {
public:
    string toHex(int num) {
        if(num == 0)    return "0";
        long long k = 1 ;
        unsigned int p = 1ll*INT_MAX*2 + 1;
        if(num < 0) p = p + num + 1;
        else    p = num;
        int t , l = 1;
        while(k < p)  k = k << 4 , l++;
        if(k > p) k = k >> 4 , l--;
        string ans;
        while(l--){
            t = p/k;
            p -= t*k;
            k = k >> 4;
            if(t >= 0 and t <= 9)   ans += ('0'+t);
            else    ans += ('a'+t%10);
        }
        return ans;
    }
};