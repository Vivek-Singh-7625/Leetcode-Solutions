class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int m = knowledge.size() , n = s.length();
        bool work;
        string t , ans;
        unordered_map<string,string> mpp;
        for(int i = 0 ; i < m ; i++)    mpp[knowledge[i][0]] = knowledge[i][1];
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')'){
                work = true;
                if(mpp[t] != ""){
                    ans += mpp[t];
                    work = false;
                }
                if(work)    ans += '?';
                t = "";
            }
            else{
                if(s[i] == '('){
                    while(s[++i] != ')')    t += s[i];
                    i = i-1;
                }
                else    ans += s[i];
            }
        }
        return ans;
    }
};