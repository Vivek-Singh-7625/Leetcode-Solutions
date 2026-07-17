class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> A(52,0);
        int n = s.length() , ans = 0 , x = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' and s[i] <= 'z') A[s[i]-'a']++;
            else if(s[i] >= 'A' and s[i] <= 'Z')    A[s[i]-'A'+26]++;
        }
        for(int i = 0 ; i < 52 ; i++){
            if(A[i]%2){  
                ans += A[i] - 1;
                x = 1;
            }
            else ans += A[i];
        }
        return ans + x ;
    }
};