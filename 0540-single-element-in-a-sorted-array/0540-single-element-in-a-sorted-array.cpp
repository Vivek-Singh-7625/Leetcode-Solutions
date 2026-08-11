class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n-1 , mid , x , y;
        while(low <= high){
            mid = (high-low)/2 + low ;
            x = (mid - 1 >= 0) ? nums[mid-1] : -1; 
            y = (mid + 1 < n) ? nums[mid+1] : -1; 
            if(nums[mid] != x and nums[mid] != y)   return nums[mid];
            else if(mid%2){
                if(nums[mid] == nums[mid-1])    low = mid+1;
                else    high = mid - 1;
            }
            else{
                if(nums[mid] == nums[mid+1])    low = mid+1;
                else    high = mid - 1;
            }
        }
        return -1;
    }
};