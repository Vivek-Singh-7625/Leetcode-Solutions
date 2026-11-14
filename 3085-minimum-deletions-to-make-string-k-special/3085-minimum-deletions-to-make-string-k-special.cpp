class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> mpp;
        for(char c : word)  mpp[c]++;

        vector<int> arr;
        for(auto& [k,v] : mpp)  arr.push_back(v);
        sort(arr.begin(),arr.end());
        
        int n = arr.size() , ans = INT_MAX , del;
        if((arr[n-1] - arr[0]) <= k)  return 0;
        for(int i : arr){
            del = 0;
            for(int x : arr){
                if(del > ans)   break;
                if(i > x)   del += x;
                if(i + k < x)   del += (x - i - k);
            }
            ans = min(del,ans);
        }
        return ans;
    }
};