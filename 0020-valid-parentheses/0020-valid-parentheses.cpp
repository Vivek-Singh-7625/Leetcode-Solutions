class Solution {
public:
    char bracket_open(char c){
        if(c == ')')    return '(';
        else if(c == '}')   return '{';
        else if(c == ']')   return '[';
        return 0;
    }
    bool isValid(string& s) { 
        int top = -1;
        vector<char> p;
        if (s.size()%2) return 0;
        for (char c: s){
            if(c == '(' or c == '[' or c == '{')    p.push_back(c),top++;
            else if (top == -1 || p[top] != bracket_open(c))   return 0;
            else p[top--] , p.pop_back();
        }
        return top==-1;
    }
};