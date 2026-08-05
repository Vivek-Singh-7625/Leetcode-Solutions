class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int l = n , r = n;
        helper(l , r , "" , ans);
        return ans;
    }
    void helper(int left , int right , string t , vector<string>& ans){
        if(left == 0 and right == 0){    
            ans.push_back(t);
            return ;
        }
        if(left)    helper(left - 1 , right , t + "(" , ans);
        if(right > left)   helper(left , right - 1 , t + ")" , ans);
    }
};