class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i = 0;
        for(int& x : nums){
            if(x == target) ans.push_back(i);
            i++;
            if(x > target)  break;
        }
        return ans;
    }
};