class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0 , high , mid , x = INT_MAX, y = INT_MIN , n = weights.size();
        for(int i = 0 ; i < n ; i++){
            x = min(x,weights[i]);
            y = max(y,weights[i]);
        }
        int t , s;
        high = y*(n+days-1)/days;
        while(low < high){
            mid = low + (high - low)/2;
            t = 1 , s = 0;
            for(int i = 0 ; i < n ; i++){
                if(mid < y){
                    t = days + 2;
                    break;
                }
                s += weights[i];
                if(s > mid){
                    s = weights[i];
                    t++;
                }
            }
            if(t <= days)   high = mid;
            else    low = mid + 1;
        }
        return low;
    }
};