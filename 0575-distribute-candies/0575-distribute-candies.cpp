class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mpp;
        int n = candyType.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!mpp[candyType[i]]){
                ans++;
                mpp[candyType[i]] = 1;
            }
            if(ans >= n/2) return n/2;
        }
        return ans;
    }
};