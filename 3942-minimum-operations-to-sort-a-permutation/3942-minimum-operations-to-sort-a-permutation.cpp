class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int idx = find(nums.begin(), nums.end(), 0) - nums.begin() , val;
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            val = nums[(idx + i) % n];
            if(val != i)    asc = false;
            if(val != n - i)    desc = false;
            if(!asc && !desc)   return -1;
        }
        if (asc)    return min(idx, n - idx + 2);
        return min(n - idx, idx + 2);
    }
};