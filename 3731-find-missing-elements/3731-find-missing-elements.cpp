class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size() ;
        int k = nums[0];
        for(int i = 0 ; i < n ; i++){
            while(k != nums[i]){
                ans.push_back(k);
                k++;
            }
            k++;
        }
        return ans;
    }
};