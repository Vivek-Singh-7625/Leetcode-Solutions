class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MAX , high , mid , x = 0 ,  y = INT_MIN , n = weights.size();
        int t , s;
        for(int i = 0 ; i < n ; i++){
            low = min(low,weights[i]);
            y = max(y,weights[i]);
            x += weights[i];
        }
        high = x;
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