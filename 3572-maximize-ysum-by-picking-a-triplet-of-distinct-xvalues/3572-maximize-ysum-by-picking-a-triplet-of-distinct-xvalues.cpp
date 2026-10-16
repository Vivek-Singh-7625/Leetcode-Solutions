class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int k = 1 , n = y.size() , t;
        unordered_map<int,int> mpp;
        for(int a : x){
            if(mpp[a] == 0) mpp[a] = k++;
        }
        vector<int> ans(k);
        if(k < 4)   return -1;
        for(int i = 0 ; i < n ; i++){
            t = mpp[x[i]];
            ans[t] = max(ans[t],y[i]);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1] + ans[k-2] + ans[k-3];
    }
};