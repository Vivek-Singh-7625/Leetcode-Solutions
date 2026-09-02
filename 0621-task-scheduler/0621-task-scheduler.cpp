class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mpp;
        int mx = 0;
        for(char& c : tasks){ 
            mpp[c]++;
            mx = max(mpp[c],mx);
        }
        int ans = (mx-1)*(n+1);
        for(auto& [k,v] : mpp){
            if(v == mx) ans++;
        }
        return max(ans,(int)tasks.size());
    }
};