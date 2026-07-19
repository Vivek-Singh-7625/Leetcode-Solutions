class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        int n = nums1.size() , m = nums2.size();
        int flag = (m > n) ? 1 : 0;
        vector<int> ans;
        for(int i = 0 ; i < min(n,m) ; i++){
            if(flag)    mpp[nums1[i]]++;
            else mpp[nums2[i]]++;
        }
        for(int i = 0 ; i < max(m,n) ; i++){
            if(flag){
                if(mpp[nums2[i]]){
                    mpp[nums2[i]]--;
                    ans.push_back(nums2[i]);
                }
            }
            else{
                if(mpp[nums1[i]]){
                    mpp[nums1[i]]--;
                    ans.push_back(nums1[i]);
                }
            }
        }
        return ans;
    }
};