class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX , ans = 0;
        for(int x : nums)   mn = min(mn,x); 
        for(int x : nums)   ans += (x-mn); 
        return ans;
    }
};