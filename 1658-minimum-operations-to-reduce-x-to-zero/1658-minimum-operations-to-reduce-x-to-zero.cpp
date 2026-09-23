class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() , ans = 0 , val = 0 , t = 0;
        for(int i = 0 ; i < n ; i++)    val += nums[i];
        if(val == x)    return n;
        val -= x;
        if(val < 0) return -1;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            t += nums[i];
            while(t > val){
                t -= nums[l++];
            }
            if(t == val)    ans = max(ans,i-l+1);
        }
        if(ans == 0)    return -1;
        return n-ans;
    }
};