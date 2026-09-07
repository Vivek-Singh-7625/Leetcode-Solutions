class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n+1,0) , s(n+1,0);
        p[1] = nums[0];
        s[n-1] = nums[n-1];
        for(int i = 2 ; i <= n ; i++){
            p[i] = p[i-1] | nums[i-1];
            s[n-i] = s[n-i+1] | nums[n-i];
        }
        long long ans = 0 , pw = (1 << k);
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,p[i] | (1LL*nums[i]*pw) | s[i+1]);
        }
        return ans;
    }
};