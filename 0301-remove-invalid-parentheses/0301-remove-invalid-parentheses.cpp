class Solution {
public:
    int mx = 0;
    unordered_set<string> valid;

    void helper(int idx, int t, string& s, string& p) {
        if(t < 0)
            return;

        if(idx == s.size()) {
            if(t == 0) {
                if(p.size() > mx) {
                    mx = p.size();
                    valid.clear();
                    valid.insert(p);
                }
                else if(p.size() == mx) {
                    valid.insert(p);
                }
            }
            return;
        }
        if(s[idx] == '(' || s[idx] == ')') {
            helper(idx + 1, t, s, p);
        }
        if(s[idx] == '(') {
            p.push_back('(');
            helper(idx + 1, t + 1, s, p);
            p.pop_back();
        }
        else if(s[idx] == ')') {
            if(t > 0) {
                p.push_back(')');
                helper(idx + 1, t - 1, s, p);
                p.pop_back();
            }
        }
        else {
            p.push_back(s[idx]);
            helper(idx + 1, t, s, p);
            p.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        string p;
        helper(0, 0, s, p);
        return vector<string>(valid.begin(), valid.end());
    }
};