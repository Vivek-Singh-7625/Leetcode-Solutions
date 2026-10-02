class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        int n = s.length() ;
        stack<char> a ;
        queue<char> b ;
        for(char c : s){
            a.push(c);
            if(c == ')'){
                a.pop();
                while(a.top() != '('){
                    b.push(a.top());
                    a.pop();
                }
                a.pop();
                while(!b.empty()){   
                    a.push(b.front());
                    b.pop();
                }
            }
        }
        while(!a.empty()){
            ans += a.top();
            a.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};