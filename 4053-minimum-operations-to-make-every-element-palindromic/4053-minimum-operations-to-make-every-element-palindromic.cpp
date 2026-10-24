class Solution {
public:
    inline static vector<long long> odd , even;
    void solver(){
        if(!odd.empty() && !even.empty()) return;
        long long x;
        string s , a , b;
        for(int i = 1 ; i < 1e5 ; i++){
            s = to_string(i);
            a = s;
            for(int i = s.length() - 1 ; i >= 0 ; i--)  a += s[i];
            x = stoll(a);
            if (x <= 1e9) {
                if (x & 1) odd.push_back(x);
                else even.push_back(x);
            }
            b = s;
            for (int i = s.length() - 2; i >= 0; i--)  b += s[i];
            x = stoll(b);
            if (x <= 1e9) {
                if (x & 1) odd.push_back(x);
                else even.push_back(x);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
    }
    long long minOperations(vector<int>& nums) {
        long long p;
        long long ans = 0;
        solver();
        for(int x : nums){
            auto& arr = (x&1) ? odd : even;
            auto it = lower_bound(arr.begin(),arr.end(),x);
            p = 1e16;
            if (it != arr.end())     p = (*it - x) / 2;
            if (it != arr.begin())  p = min(p, (x - *prev(it)) / 2);
            ans += p;
        }
        return ans;
    }
};