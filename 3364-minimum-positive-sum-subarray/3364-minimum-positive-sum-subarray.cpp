class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX , n = nums.size() , t;
        for(int i = 1 ; i < n ; i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = l ; j <= r ; j++){
                if(i - j < -1)  break;
                if(i - j == -1) t = nums[i];
                else    t = nums[i] - nums[i-j];
                if(t > 0)   ans = min(ans, t);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};