class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size() , t;
        unordered_map<int,int> mpp;
        long long ans = 0;
        mpp.reserve(10);
        vector<int> gain(n);
        for(int i = 0 ; i < n ; i++){
            t = nums[i];
            while(t){
                mpp[t%10]++;
                t = t/10;
            }
            for(int i = 9 ; i >= 0 ; i--){
                while(mpp[i]){
                    mpp[i]--;
                    t = i + t*10;
                }
            }
            gain[i] = (t - nums[i]);
            ans += nums[i];
        }
        sort(gain.begin(),gain.end());
        while(k--){
            n--;
            ans += gain[n];
        }
        return ans;
    }
};