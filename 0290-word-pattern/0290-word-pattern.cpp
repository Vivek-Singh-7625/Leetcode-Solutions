class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,int> mpp;
        unordered_map<int,string> mp;
        int n = pattern.length();
        stringstream ss(s);
        string temp;
        for(int i = 0 ; i < n ; i++){
            if (!(ss >> temp))  return false;
            if(mpp[temp] == 0){
                mpp[temp] = pattern[i]-'a'+1;
            }
            else{
                if(mpp[temp] != pattern[i]-'a'+1)   return false;
            }
            if(mp[pattern[i]-'a'+1] == ""){
                mp[pattern[i]-'a'+1] = temp;
            }
            else{
                if(mp[pattern[i]-'a'+1] != temp)   return false;
            }
        }
        if (ss >> temp)  return false;
        return true;
    }
};