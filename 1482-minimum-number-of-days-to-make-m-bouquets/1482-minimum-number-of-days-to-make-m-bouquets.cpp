class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX , high = 0 , mid , n = bloomDay.size();
        for(int x : bloomDay){
            low = min(low,x);
            high = max(high,x);
        }
        if(1LL*m*k > n) return -1;
        int l = 0 , y = 0;
        while(low < high){
            mid = low + (high - low)/2;
            y = 0;
            for(int x : bloomDay){
                if(x <= mid)    l++;
                else{
                    y += (l/k);
                    l = 0;
                }
            }
            y += (l/k);
            l = 0;
            if(m <= y)  high = mid;
            else    low = mid + 1;
        }
        return low;
    }
};