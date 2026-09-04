class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MAX, t = nums[0];
        vector<int> a(n);
        a[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--)    a[i] = min(nums[i],a[i+1]);
        for(int i = 0 ; i < n ; i++){    
            t = max(nums[i],t);
            ans = min(ans,t-a[i]);
            if(ans <= k)    return i;
        }
        return -1 ;
    }
};