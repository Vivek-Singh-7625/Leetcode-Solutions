class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = nums[0] , mid , n = nums.size() , s = 0;
        for(int i = 1 ; i < n ; i++){
            high = max(high,nums[i]);
        }
        while(low < high){
            mid = low + (high - low)/2;
            s = 0;
            for(int i = 0 ; i < n ; i++)    s += (nums[i]+mid-1)/mid;
            if(s <= threshold)  high = mid;
            else    low = mid + 1;
        }
        return low;
    }
};