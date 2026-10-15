class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size() , count = 0 , ans = 0;
        vector<int> mpp(101,0);
        for(int i = 0 ; i < n ; i++){
            count = 0;
            for(int j = i ; j < n ; j++){
                if(mpp[nums[j]] == 0)   count++;
                mpp[nums[j]]++;
                ans += (count*count);
            }
            for(int j = 0 ; j <= 100 ; j++)    mpp[j] = 0;
        }
        return ans;
    }
};