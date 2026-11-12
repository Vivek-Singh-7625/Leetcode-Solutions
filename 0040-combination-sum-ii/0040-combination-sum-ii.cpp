class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        solver(ans, candidates, r, target, 0 );
        return ans;
    }
    void solver(vector<vector<int>>& ans , vector<int>& c , vector<int>& r , int target , int i ){
        if (target == 0) {
            ans.push_back(r);
            return;
        }
        if (target < 0 || i == c.size()) return;

        r.push_back(c[i]);
        solver(ans, c, r, target - c[i], i + 1);
        r.pop_back();

        while (i + 1 < c.size() && c[i] == c[i + 1])    i++;
        solver(ans, c, r, target, i + 1);
    }
};