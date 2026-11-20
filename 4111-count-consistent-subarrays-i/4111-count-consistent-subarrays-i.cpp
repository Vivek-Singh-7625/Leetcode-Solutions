class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size() , ans = n , t , mn;
        for(int i = 0 ; i < n ; i++){
            mn = nums[i] , t = nums[i];
            for(int j = i + 1 ; j < n ; j++){
                t = (t&nums[j]);
                mn = min(mn,nums[j]);
                if(t == mn)    ans++;
            }
        }
        return ans;
    }
};