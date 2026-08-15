class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> A;
        A.push_back("abc");
        A.push_back("def");
        A.push_back("ghi");
        A.push_back("jkl");
        A.push_back("mno");
        A.push_back("pqrs");
        A.push_back("tuv");
        A.push_back("wxyz");
        vector<string> temp;
        temp.push_back("");
        int idx , len = 0;
        for(int i = 0 ; i < digits.size() ; i++){
            idx = digits[i]-'2';
            while(temp[0].size() == len){
                for(int k = 0 ; k < A[idx].size() ; k++){
                    temp.push_back(temp[0]+A[idx][k]);
                }
                temp.erase(temp.begin());
            }
            len++;
        }
        return temp;
    }
};