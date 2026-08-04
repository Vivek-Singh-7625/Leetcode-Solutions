class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(100);
        vector<int> ans;
        int a = INT_MIN  , b = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            a = max(a,nums[i]);
            b = min(b,nums[i]);
            v[nums[i]-1] = 1;
        }
        for(int i = b-1 ; i < a ; i++){
            if(!v[i])   ans.push_back(i+1);
        }
        return ans;
    }
};