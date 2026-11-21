class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int t ;
        vector<bool> ans(32,0);
        for(int x : nums){
            t = log2(x);
            if((x & (x - 1)) == 0)  ans[t] = true;
        }
        for(int i = 0 ; i < 32 ; i++){
            if(!ans[i]) return (1 << i);
        }
        return -1;
    }
};