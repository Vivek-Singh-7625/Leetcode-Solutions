class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = to_string(nums[0]);
        if(n == 1)  return ans;
        if(n == 2)  return ans + "/" + to_string(nums[1]);
        ans += "/(";
        for(int i = 1 ; i < n ; i++){
            ans += to_string(nums[i]);
            if(i != n-1)    ans += "/";
        }
        return ans + ")";
    }
};