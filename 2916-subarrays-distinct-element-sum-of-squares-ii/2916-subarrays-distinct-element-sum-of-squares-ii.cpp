class Solution {
    const static int MOD = 1e9 + 7;
    class SegmentTree {
        vector<long long> sum, SQsum, lazy;
        int n;
        void helper(int node, int l, int r, long long delta) {
            long long len = r - l + 1;
            long long d = delta % MOD;
            long long addSq = ((2LL * d % MOD) * sum[node] % MOD + (d * d % MOD) * len % MOD) % MOD;
            SQsum[node] = (SQsum[node] + addSq) % MOD;
            sum[node] = (sum[node] + d * len) % MOD;
            lazy[node] += delta;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r)  return;
            int mid = l + (r - l) / 2;
            helper(node * 2, l, mid, lazy[node]);
            helper(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }

        void update(int node , int l , int r , int ql , int qr , long long delta) {
            if (qr < l || r < ql)   return;
            if (ql <= l && r <= qr) {
                helper(node, l, r, delta);
                return;
            }
            push(node, l, r);
            int mid = l + (r - l) / 2;
            update(node * 2, l, mid, ql, qr, delta);
            update(node * 2 + 1, mid + 1, r, ql, qr, delta);
            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            SQsum[node] = (SQsum[node * 2] + SQsum[node * 2 + 1]) % MOD;
        }

    public:
        SegmentTree(int size) : n(size) {
            sum.assign(4 * n, 0);
            SQsum.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        void update(int l, int r, long long delta) {
            if (l <= r) update(1, 0, n - 1, l, r, delta);
        }

        long long getSQsum() {
            return SQsum[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1;
            auto it = last.find(nums[i]);
            if (it != last.end()) prev = it->second;
            st.update(prev + 1, i, 1);
            ans = (ans + st.getSQsum()) % MOD;
            last[nums[i]] = i;
        }
        return ans;
    }
};