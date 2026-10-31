class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
        vector<string> ans;
        unordered_map<int,int> mpp;
        for(char c : r1)    mpp[c] = 1;
        for(char c : r2)    mpp[c] = 2;
        for(char c : r3)    mpp[c] = 3;

        int row = -1;
        bool valid = false;
        char t;
        for(string x : words){
            t = t = tolower(x[0]);
            row = mpp[t];
            valid = true;
            for(char c : x){
                t = tolower(c);
                if(mpp[t] != row){
                    valid = false;
                    break;
                }
            }
            if(valid)   ans.push_back(x);
        }
        return ans;
    }
};