class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long x = LLONG_MIN , y = LLONG_MIN , z = LLONG_MIN;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > x){
                z = y;
                y = x;
                x = nums[i];
            }
            else if(nums[i] > y and (nums[i] != x)){
                z = y;
                y = nums[i];
            }
            else if(nums[i] > z and (nums[i] != x and nums[i] != y)){
                z = nums[i];
            }
        }
        if(z == LLONG_MIN)    return x;
        return z;
    }
};