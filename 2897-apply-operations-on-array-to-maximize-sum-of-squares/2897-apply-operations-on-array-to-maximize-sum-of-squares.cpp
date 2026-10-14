class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(32);
        int n = nums.size() , t ;
        for(int i = 0 ; i < n ; i++){
            t = nums[i];
            for(int j = 0 ; j < 32 ; j++){
                if(t & (1 << j))    bit[j]++;
            }
        }
        int ans = 0 , mod = 1e9 + 7;
        bool end = true;
        for(int i = 0 ; i < k ; i++){
            t = 0;
            for(int j = 0 ; j < 32 ; j++){
                if(bit[j]){
                    end = false;
                    bit[j]--;
                    t += (1 << j);
                }    
            }
            ans = (ans + 1ll*t*t)%mod;
            if(end) break;
        }
        return ans;
    }
};