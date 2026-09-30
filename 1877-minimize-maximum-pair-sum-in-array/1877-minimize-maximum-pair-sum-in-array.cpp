class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0 , e = nums.size()-1 , sum = INT_MIN;
        while(e > s){
            if(nums[s] + nums[e] > sum) sum = nums[s] + nums[e];
            s++;
            e--;
        }
        return sum;
    }
};