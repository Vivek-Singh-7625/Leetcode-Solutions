class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size() , x , y;
        unordered_map<int,int> mpp;
        vector<int> p = nums;
        mpp.reserve(n);
        for(int i = 0 ; i < n ; i++){
            x = nums[i];
            y = 0;
            while(x){
                y += x%10;
                x = x/10;
            }
            mpp[nums[i]] = y;
        }
        int swaps = 0;
        auto cmp = [&](int a, int b) {
            if(mpp[a] == mpp[b]){
                return a < b;
            }
            return mpp[a] < mpp[b];
        };
        sort(nums.begin(),nums.end(),cmp);
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            while (p[i] != nums[i]) {
                swap(p[mpp[p[i]]], p[i]);
                swaps++;
            }
        }
        return swaps;
    }
};