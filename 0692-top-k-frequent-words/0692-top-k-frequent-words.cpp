class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        int n = words.size() , t = 0;
        vector<string> ans;
        for(int i = 0 ; i < n ; i++){
            if(mpp[words[i]] == 0)  ans.push_back(words[i]);
            t = max(t,++mpp[words[i]]);
        }
        auto cmp = [&](string a , string b){
            if(mpp[a] == mpp[b])    return a < b;
            return mpp[a] > mpp[b];
        };
        sort(ans.begin(),ans.end(),cmp);
        ans.resize(k);
        return ans;
    }
};