class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string temp , ans;
        while(ss >> temp){
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans += " ";
        }
        if(!ans.empty())    ans.pop_back();
        return ans;
    }
};