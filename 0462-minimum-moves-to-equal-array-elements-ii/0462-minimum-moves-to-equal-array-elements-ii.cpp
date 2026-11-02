class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long low = -1e9, high = 1e9, mid;
        long long n = nums.size(), ans = LLONG_MAX;

        while(low <= high){
            mid = low + (high - low)/2;
            long long sum = 0, sum2 = 0;
            for(int x : nums){
                sum += abs(x - mid);
                sum2 += abs(x - (mid + 1));
            }
            ans = min(ans, sum);
            if(sum < sum2)  high = mid - 1;
            else    low = mid + 1;
        }

        return ans;
    }
};