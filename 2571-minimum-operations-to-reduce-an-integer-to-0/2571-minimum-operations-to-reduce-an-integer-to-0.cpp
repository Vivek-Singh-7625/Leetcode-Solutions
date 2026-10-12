class Solution {
public:
    int minOperations(int n) {
        int ans = 0 ;
        while(n){
            if(n&1){
                if(((n+1)&2) != 2)    ans++ , n++;
                else    ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
};