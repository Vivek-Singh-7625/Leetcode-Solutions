class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        int k = 0;
        auto cmp = [&](int a , int b){
            return abs(a) < abs(b);
        };
        sort(arr.begin(),arr.end(),cmp);
        int x;
        for(int i = 0 ; i < n ; i++)    mpp[arr[i]]++;
        for(int i = 0 ; i < n ; i++){
            x = arr[i]*2;
            if(mpp[x] and mpp[x/2]){
                if(x == 0 and mpp[x] == 1)  continue;
                mpp[x/2]--;
                mpp[x]--;
                k++;
            }
        }
        return k >= n/2;
    }
};