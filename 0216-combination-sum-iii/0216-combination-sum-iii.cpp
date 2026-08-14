class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums(9);
        vector<int> t;
        if(n > 45)  return ans;
        for(int i = 0 ; i < 9 ; i++)    nums[i] = i+1;
        solve(ans,nums,k,n,t,0);
        return ans;
    }
    void solve(vector<vector<int>>& ans, vector<int>& nums , int k , int target , vector<int>& t , int idx){
        if(target == 0){
            if(t.size() == k )  ans.push_back(t);
            return;
        }
        if(t.size() == k and target != 0)   return;
        if(idx > 8) return;
        if(target >= nums[idx]){
            t.push_back(nums[idx]);
            solve(ans,nums,k,target-nums[idx],t,idx+1);
            t.pop_back();
        }
        solve(ans,nums,k,target,t,idx+1);
    }
};