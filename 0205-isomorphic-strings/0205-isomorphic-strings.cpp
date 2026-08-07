class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> mpp;
        unordered_map<int,int> mp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(mpp[s[i]] == 0)  mpp[s[i]] = t[i] + 1;
            else if(mpp[s[i]] != t[i] + 1)  return false;
            if(mp[t[i]] == 0)  mp[t[i]] = s[i] + 1;
            else if(mp[t[i]] != s[i] + 1)  return false;
        }
        return true;
    }
};