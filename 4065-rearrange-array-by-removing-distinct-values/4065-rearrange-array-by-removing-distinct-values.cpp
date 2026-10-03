class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() , k = 0;
        vector<int> d , ans(n);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            if(!mpp[nums[i]])   d.push_back(nums[i]);
            mpp[nums[i]]++;
        }
        sort(d.begin(),d.end());
        for(int i = 0 ; i < n ; i++){
            for(int&v : d){
                if(mpp[v]){
                    mpp[v]--;
                    ans[k++] = v;
                }
            }
            if(k == n)  break;
        }
        return ans;
    }
};