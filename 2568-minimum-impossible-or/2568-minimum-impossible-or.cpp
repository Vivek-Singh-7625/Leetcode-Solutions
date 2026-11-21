class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = nums.size() , t ;
        vector<bool> ans(32,0);
        for(int i = 0 ; i < n ; i++){
            t = log2(nums[i]);
            if(nums[i] == (1 << t)) ans[t] = true;
        }
        for(int i = 0 ; i < 32 ; i++){
            if(!ans[i]) return (1 << i);
        }
        return -1;
    }
};