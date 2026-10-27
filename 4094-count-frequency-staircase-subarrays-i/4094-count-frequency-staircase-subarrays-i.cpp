class Solution {
public:
    int countStaircase(vector<int>& nums) {
        vector<int> distinct;
        int n = nums.size() , x , ans = 0 , s;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                x = nums[j];
                if(mpp[x] == 0) distinct.push_back(x);
                mpp[x]++;

                s = distinct.size();
                for(int k = 0 ; k < distinct.size() ; k++){
                    x = distinct[k];
                    if(mpp[x] != k+1)   break;
                    if(k == s - 1)  ans++;
                }
            }
            distinct.clear();
            mpp.clear();
        }
        return ans;
    }
};