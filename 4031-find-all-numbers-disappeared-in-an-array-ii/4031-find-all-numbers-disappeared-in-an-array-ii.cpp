class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size() , p = lower;
        vector<vector<int>> ans;
        set<int> s;
        for(int i = 0 ; i < n ; i++)    s.insert(nums[i]);
        for(int x : s){
            if(x < lower) continue;
            if(x > upper) break;
            if(x == p)    p = x + 1;
            else{
                ans.push_back({p,x-1});
                p = x + 1;
            }
        }
        if(p <= upper)   ans.push_back({p,upper});
        return ans;
    }
};