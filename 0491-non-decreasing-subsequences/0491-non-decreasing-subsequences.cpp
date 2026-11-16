class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solver(ans , temp , nums , 0);
        return ans;
    }
    void solver(vector<vector<int>>& ans , vector<int>& temp , vector<int>& nums , int idx){
        if(temp.size() > 1)   ans.push_back(temp);
        unordered_set<int> st;
        for(int i = idx ; i < nums.size() ; i++){
            if((temp.empty() or temp.back() <= nums[i]) and st.insert(nums[i]).second){
                temp.push_back(nums[i]);
                solver(ans , temp , nums , i+1);
                temp.pop_back();
            }
        }
    }
};