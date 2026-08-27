class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int n = nums.size();
        if(nums[n-1] > nums[n-2])    return n-1;
        if(nums[0] > nums[1])    return 0;
        int low = 1 , high = nums.size() - 1 , mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return  mid;
            else if(nums[mid] < nums[mid+1])    low = mid+1;
            else    high = mid-1;
        }
        return  -1;
    }
};