class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() , ans , t = nums[0];
        vector<int> a(n);
        a[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--)    a[i] = min(nums[i],a[i+1]);
        ans = nums[0] - a[0];
        if(ans <= k)    return 0;
        for(int i = 1 ; i < n ; i++){    
            t = max(nums[i],t);
            ans = min(ans,t-a[i]);
            if(ans <= k)    return i;
        }
        return -1 ;
    }
};