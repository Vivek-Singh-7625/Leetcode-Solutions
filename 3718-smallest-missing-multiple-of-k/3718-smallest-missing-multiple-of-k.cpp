class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> b(100,false);
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%k == 0)  b[nums[i]/k - 1] = true;;
        }
        for(int i = 0 ; i < n ; i++){
            if(!b[i])  return (i+1)*k;
        }
        return k*(n+1);
    }
};