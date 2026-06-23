class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> HT;
        vector<int> res(2,-1);
        int x;
        for(int i = 0 ; i < nums.size() ; i++){
            x = nums[i];
            if(HT[target-x]){ 
                res[0] = HT[target-x] -1;
                res[1] = i;
                break;
            }
            HT[x] = i+1;
        }
        return res;
    }
};