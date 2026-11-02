class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int a , b;
        if(n == 1)  return 0;
        if(n%2){
            a = nums[n/2];
            b = nums[n/2];
        }
        else{
            a = nums[n/2];
            b = nums[n/2 - 1];
        }
        int ans1 = 0 , ans2 = 0;
        for(int x : nums){
            ans1 += abs(x-a);
            ans2 += abs(x-b);
        }
        return min(ans1,ans2);
    }
};