class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        auto cmp = [&](int a , int b){
            return abs(a) < abs(b);
        };
        sort(arr.begin(),arr.end(),cmp);
        for (int& x : arr)  mpp[x]++;
        for (int& x : arr){
            if(mpp[x]){
                if(mpp[2*x] <= 0)   return false;
                mpp[x]--;
                mpp[2*x]--;
            }
        }
        return true;
    }
};