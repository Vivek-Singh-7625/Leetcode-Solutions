class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int x = nums[0] , count = 1 , n = nums.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            count = 0;
            for(int j = i ; j < n ; j++){
                if(nums[j] == target)   count++;
                if(count > (j-i+1)/2)   ans++;
            }
        }
        return ans;
    }
};