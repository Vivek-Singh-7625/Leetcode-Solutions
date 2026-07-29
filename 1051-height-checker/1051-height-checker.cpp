class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int freq[101] = {0};
        for (int h : heights) {
            freq[h]++;
        }

        int ans = 0 , idx = 0;

        for (int height = 1; height <= 100; height++) {
            while (freq[height]) {
                if (heights[idx] != height) {
                    ans++;
                }
                idx++;
                freq[height]--;
            }
        }

        return ans;
    }
};
