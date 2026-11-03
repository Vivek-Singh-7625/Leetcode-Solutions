class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() , sum = 0 , mx = -1;
        for(int& x : nums){
            sum += x;
            mx = max(mx,x);
        }
        return n*mx - sum;
    }
};