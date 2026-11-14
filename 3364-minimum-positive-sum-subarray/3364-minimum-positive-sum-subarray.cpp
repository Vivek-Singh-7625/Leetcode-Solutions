class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size() , ans = INT_MAX , sum;
        for (int k = l ; k <= r ; k++) {
            sum = 0;
            for (int i = 0 ; i < n ; i++) {
                sum += nums[i] ;
                if (i >= k) sum -= nums[i - k] ;
                if (i >= k - 1 && sum > 0) ans = min(sum,ans);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};