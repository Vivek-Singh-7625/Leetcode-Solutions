class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX , n = nums.size() , x;
        string a , b;
        for(int i = 0 ; i < n ; i += 2){
            a = to_string(nums[i]);
            b = to_string(nums[i+1]);
            x = stoi(a+b);
            ans = min(ans,x);
        }
        return ans;
    }
};