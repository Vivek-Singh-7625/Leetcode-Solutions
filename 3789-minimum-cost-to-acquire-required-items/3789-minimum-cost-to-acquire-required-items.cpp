class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int common = min(need1,need2);
        int diff1 = need1 - common , diff2 = need2 - common;
        long long ans = 0 , t = 1ll*costBoth*(max(need1,need2));
        if(cost1 + cost2 > costBoth)    ans += 1ll*costBoth*common;
        else    ans += 1ll*(cost1 + cost2)*common;
        return min(ans + 1ll*diff1*cost1 + 1ll*diff2*cost2 , t);
    }
};