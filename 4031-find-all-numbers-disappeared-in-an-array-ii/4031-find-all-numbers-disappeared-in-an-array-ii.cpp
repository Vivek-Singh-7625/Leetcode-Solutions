class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size() , p = lower;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < lower) continue;
            if(nums[i] > upper) break;
            if(i and nums[i] == nums[i-1]) continue;
            if(nums[i] == p)    p++;
            else{
                ans.push_back({p,nums[i]-1});
                p = nums[i] + 1;
            }
        }
        if(p <= upper)   ans.push_back({p,upper});
        return ans;
    }
};