class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size() , t = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < i) continue;
            t = 0;
            while(nums[i]){
                t += nums[i]%10;
                nums[i] = nums[i]/10;
            }
            if(t == i)  return i;
        }
        return -1;
    }
};