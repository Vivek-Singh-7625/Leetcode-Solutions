class Solution {
public:
    const int MOD = 1000000007;
    int minimumCost(vector<int>& nums, int k) {
        int temp = k , n = nums.size() ;
        long long x = 0 , y; 
        for(int i = 0 ; i < n ; i++){
            if(temp < nums[i]){
                y = (1LL*nums[i]-temp+k-1)/k;
                x += y;
                x = x%MOD;
                temp += y*k;
            }
            temp = temp - nums[i];
        }
        long long ans = 1LL*x*(x+1)/2;
        ans = ans%MOD;
        temp = ans;
        return temp;
    }
};