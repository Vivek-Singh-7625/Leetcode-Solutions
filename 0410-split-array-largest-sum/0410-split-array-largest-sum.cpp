class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() , low = INT_MAX , high = INT_MIN , sum = 0 , mid;
        for(int i = 0 ; i < n ; i++){
            low = min(low,nums[i]);
            sum += nums[i];
        }
        int x = 0 , t = 0;
        high = sum;
        while(low <= high){
            mid = low + (high-low)/2;
            x = 1 , t = 0;
            for(int i = 0 ; i < n ; i++){
                if(t + nums[i] <= mid)  t += nums[i];
                else{
                    if(nums[i] > mid){
                        x = INT_MAX ; 
                        break;
                    }
                    x++;
                    t = nums[i];
                }
            }
            if(x <= k)  high = mid - 1;
            else    low = mid + 1;
        }
        return low;
    }
};