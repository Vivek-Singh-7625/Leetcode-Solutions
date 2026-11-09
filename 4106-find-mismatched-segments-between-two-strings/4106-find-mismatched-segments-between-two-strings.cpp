class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        string a1 , a2;
        int n = s1.length();
        for(int i = 0 ; i < n ; i++){
            if(s1[i] != s2[i]){
                a1 += s1[i];
                a2 += s2[i];
            }
            else{
                if(a1.size())   ans.push_back({a1,a2});
                a1 = "";
                a2 = "";
            }
        }
        if(a1.size())   ans.push_back({a1,a2});
        return ans;
    }
};