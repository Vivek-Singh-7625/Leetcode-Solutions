class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())  return ans;
        vector<string> A;
        A.push_back("abc");
        A.push_back("def");
        A.push_back("ghi");
        A.push_back("jkl");
        A.push_back("mno");
        A.push_back("pqrs");
        A.push_back("tuv");
        A.push_back("wxyz");
        backtrack(digits,0,"",ans,A);
        return ans;
    }
    void backtrack(string& digits,int idx, string x , vector<string>& ans, vector<string>& A){
        if(idx == digits.length()){
            ans.push_back(x);
            return;
        }
        string letter = A[digits[idx]-'2'];
        for(int i = 0 ; i < A[digits[idx]-'2'].size() ; i++){
            backtrack(digits,idx+1,x+A[digits[idx]-'2'][i],ans,A);
        }
    }
};