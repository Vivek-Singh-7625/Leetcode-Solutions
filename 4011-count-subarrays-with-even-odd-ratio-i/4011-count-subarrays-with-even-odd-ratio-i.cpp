class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int even = 0 , odd = 0 , n = nums.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            odd = 0 , even = 0;
            for(int j = i ; j < n ; j++){
                if(nums[j]%2)   odd++;
                else    even++;
                if(odd){
                    if(even*b <= a*odd) ans++;
                }
            }
        }
        return ans;
    }
};