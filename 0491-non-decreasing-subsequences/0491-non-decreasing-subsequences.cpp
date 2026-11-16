class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> temp;
        solver(ans , temp , nums , 0);
        for(vector<int> a : ans)   res.push_back(a); 
        return res;
    }
    void solver(set<vector<int>>& ans , vector<int>& temp , vector<int>& nums , int idx){
        int n = temp.size();
        if(idx == nums.size()){
            if(n > 1)   ans.insert(temp);
            return;
        }  
        if(n == 0 or temp[n-1] <= nums[idx]){
            temp.push_back(nums[idx]);
            solver(ans , temp , nums , idx+1);
            temp.pop_back();
        }
        solver(ans , temp , nums , idx+1);
    }
};