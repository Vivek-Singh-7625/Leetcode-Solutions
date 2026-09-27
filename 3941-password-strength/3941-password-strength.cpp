class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        vector<int> seen(256,false);
        for (char c : password) {
            if (seen[c]) continue;
            if (c >= 'a' && c <= 'z') {
                ans += 1;
                seen[c] = true;
            }
            else if (c >= 'A' && c <= 'Z') {
                ans += 2;
                seen[c] = true;
            }
            else if (c >= '0' && c <= '9') {
                ans += 3;
                seen[c] = true;
            }
            else if (c == '!' || c == '@' || c == '#' || c == '$') {
                ans += 5;
                seen[c] = true;
            }
        }
        return ans;
    }
};