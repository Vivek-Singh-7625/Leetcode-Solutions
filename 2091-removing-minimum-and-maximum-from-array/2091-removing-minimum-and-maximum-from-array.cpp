class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = 0, mn = 0 , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[mx] < nums[i])  mx = i;
            if(nums[mn] > nums[i])  mn = i;
        }
        int ans = min(max(mx+1,mn+1),max(n-mx,n-mn));
        return min({n-mx+mn+1,n-mn+mx+1,ans});
    }
};