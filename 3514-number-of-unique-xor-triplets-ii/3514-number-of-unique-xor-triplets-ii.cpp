class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans = 0 , n = nums.size() , t;
        unordered_map<int,int> mpp;
        vector<int> X;
        vector<bool> V(2049,false);
        for(int i = 0 ; i < n; i++){
            for(int j = i ; j < n; j++){
                t = nums[i]^nums[j];
                if(!V[t]) X.push_back(t);
                V[t] = true;
            }
        }
        int n2 = X.size();
        for(int i = 0 ; i < n; i++){
            for(int j = i ; j < n2; j++){
                t = X[j]^nums[i];
                if(!mpp[t]) ans++;
                else continue;
                mpp[t]++;
            }
        }
        return ans;
    }
};