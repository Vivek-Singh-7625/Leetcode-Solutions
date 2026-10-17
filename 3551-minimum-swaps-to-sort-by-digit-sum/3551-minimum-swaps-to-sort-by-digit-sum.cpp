
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), x, y;
        unordered_map<int, int> mpp;
        vector<int> p(n);

        mpp.reserve(n);

        for (int i = 0; i < n; i++) {
            x = nums[i];
            y = 0;
            p[i] = i;

            while (x) {
                y += x % 10;
                x /= 10;
            }

            mpp[nums[i]] = y;
        }

        auto cmp = [&](int a, int b) {
            if (mpp[nums[a]] == mpp[nums[b]])   return nums[a] < nums[b];
            return mpp[nums[a]] < mpp[nums[b]];
        };

        sort(p.begin(), p.end(), cmp);

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (p[i] != i) {
                swap(p[i], p[p[i]]);
                swaps++;
            }
        }

        return swaps;
    }
};
