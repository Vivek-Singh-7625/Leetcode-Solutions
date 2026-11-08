class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left&right , t;
        for(int i = 31 ; i >= 0 ; i--){
            t = (1 << i);
            if(ans&t){
                if(left + 1ll*t < right){
                    ans = ans&(~t);
                }
            }
        }
        return  ans;
    }
};