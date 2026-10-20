class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0 , n = nums.size() , drop;
        bool isvalid;
        vector<int> a(n,0);
        for(int i = 1 ; i < n ; i++)    a[i] = (nums[i] < nums[i-1]) + a[i-1];
        vector<int> prefix(n+1,0) , suffix(n+1,1e9);
        for(int i = 0 ; i < n ; i++)    prefix[i+1] = max(nums[i],prefix[i]);
        for(int i = n-1 ; i >= 0 ; i--) suffix[i] = min(nums[i],suffix[i+1]);
        for(int k = 1 ; k <= n ; k++){
            if(n%k) continue;
            isvalid = true;
            for(int i = k-1 ; i < n ; i += k){
                drop = a[i] - a[i-k+1];
                if(nums[i] > nums[i-k+1])   drop++;
                if(drop > 1 or prefix[i-k+1] > suffix[i-k+1]){
                    isvalid = false;
                    break;
                }
            }
            if(isvalid) ans += k;
        }
        return ans;
    }
};