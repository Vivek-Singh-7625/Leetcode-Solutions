class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> A(26,0);
        int n = s.length();
        int l = 0 , r = 1 , idx , ans = 2;
        A[s[0]-'a']++;
        while(l <= r and r < n){
            idx = s[r++] - 'a';
            A[idx]++;
            while(A[idx] > 2){
                A[s[l++]-'a']--;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};