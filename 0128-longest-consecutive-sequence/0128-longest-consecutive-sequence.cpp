class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0 , n = nums.size() , k , t;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++)    mpp[nums[i]]++;
        for(int i = 0 ; i < n ; i++){
            if(mpp[nums[i]] and mpp[nums[i]-1] == 0){
                k = nums[i] , t = 0;
                while(mpp[k])   mpp[k++] = 0 , t++;
                ans = max(t,ans);
            }
        }
        return ans;
    }
};