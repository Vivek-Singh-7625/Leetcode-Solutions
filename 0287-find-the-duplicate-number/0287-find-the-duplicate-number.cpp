class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> a(n) ;
        for(int i = 0 ; i < n ; i++){
            if(a[nums[i]])  return nums[i];
            a[nums[i]] = true;
        }
        return -1;
    }
};