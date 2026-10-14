class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(30, 0);
        int n = nums.size();
        int mod = 1e9 + 7 , t , common , y;
        for(int i = 0 ; i < n ; i++){
            t = nums[i];
            for(int j = 0 ; j < 30 ; j++){
                if(t & (1 << j))    bit[j]++;
            }
        }

        vector<int> cnt(30);
        for(int i = 0 ; i < 30 ; i++)   cnt[i] = min(bit[i],k);

        long long ans = 0 , x;
        for(int i = 0 ; i < 30 ; i++){
            x = (1LL << i);
            ans = (ans + 1LL * cnt[i] * x % mod * x % mod) % mod;
            for(int j = i + 1 ; j < 30 ; j++){
                common = min(cnt[i], cnt[j]);
                y = (1LL << j);
                ans = (ans + 2LL * common % mod * x % mod * y % mod) % mod;
            }
        }
        return ans;
    }
};