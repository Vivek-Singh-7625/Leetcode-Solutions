class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        int neg = INT_MIN, mx = INT_MIN, negCount = 0;
        for(auto n: nums){
            if(n) ans *= n;
            if(n < 0){ 
                neg = max(neg, n); 
                negCount++; 
            }
            mx = max(mx, n);
        }
        if(mx == 0 && negCount < 2) return 0;
        if(mx < 0 && negCount == 1) return mx;
        return (ans > 0) ? ans : ans/neg;
    }
};