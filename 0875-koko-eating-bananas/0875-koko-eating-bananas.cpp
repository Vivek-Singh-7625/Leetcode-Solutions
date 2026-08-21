class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0 , high = piles[0] , mid , n = piles.size() ;
        long long t = piles[0];
        for(int i = 1 ; i < n ; i++){
            high = max(high,piles[i]);
            t += piles[i];
        }
        if(t <= h)  return 1;
        while(low < high){
            t = n;
            mid = low + (high-low)/2;
            for(int i = 0 ; i < n ; i++)    t += (piles[i]-1)/mid;
            if(t <= h)  high = mid;
            else    low = mid+1;
        }
        return low;
    }
};