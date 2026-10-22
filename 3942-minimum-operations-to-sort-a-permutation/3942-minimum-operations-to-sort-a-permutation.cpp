class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() , k = nums[0] , res = -1;
        bool ans = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                ans = false;
                break;
            }
        }

        if (ans) {
            res = (n - k) % n;
            return min(res, n - res + 2);
        }

        k = nums[n - 1];
        ans = true;

        for (int i = 0; i < n; i++) {
            if (nums[n - 1 - i] != (k + i) % n) {
                ans = false;
                break;
            }
        }
        if (ans) {
            res = (n - k) % n;
            return 1 + min(res, n - res);
        }
        return -1;
    }
};