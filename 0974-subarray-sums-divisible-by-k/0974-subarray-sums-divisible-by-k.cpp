class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        unordered_map<int,int> mpp;
        for(int i = 1 ; i < n ; i++)  nums[i] += nums[i-1];
        for(int i = 0 ; i < n ; i++){  
            nums[i] = nums[i]%k;
            mpp[(nums[i]+k)%k]++;
        }
        ans = mpp[0]*(mpp[0]+1)/2;
        for(int i = 1 ; i < k ; i++){
            if(mpp[i]){
                ans +=  (mpp[i]-1)*(mpp[i])/2;
            }
        }
        return ans;
    }
};