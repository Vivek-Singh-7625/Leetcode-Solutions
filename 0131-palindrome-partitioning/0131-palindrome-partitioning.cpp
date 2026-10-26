class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        solver(ans,t,0,s);
        return ans;
    }
    void solver(vector<vector<string>>& ans , vector<string>& temp , int idx , string& s){
        int n = s.length();
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        string t;
        for(int i = idx ; i < n ; i++){
            t = s.substr(idx,i-idx+1);
            if(palindrome(t)){
                temp.push_back(t);
                solver(ans,temp,i+1,s);
                temp.pop_back();
            }
        }
    }
    bool palindrome(string s){
        int n = s.length();
        for(int i = 0; i < n/2 ; i++){
            if(s[i] != s[n-i-1])    return false;
        }
        return true;
    }
};