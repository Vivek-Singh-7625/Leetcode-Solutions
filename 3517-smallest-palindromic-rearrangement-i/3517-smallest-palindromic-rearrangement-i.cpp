class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> A(26,0);
        int n = s.length();
        int left = 0 , right = n-1; 
        for(int i = 0 ; i < n ; i++){
            A[s[i]-'a']++;
        }
        int idx = -1;
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < A[i]/2 ; j++){
               s[left++] = ('a' + i);
               s[right--] = ('a' + i);
            }
            if(A[i]%2)  idx = i;
        };
        if(idx != -1)   s[n/2] = ('a' + idx);
        return s;
    }
};