class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int k = 0 , p  = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            int A[256] = {0};
            for(int j = i ; j < s.length() ; j++){
                if(A[s[j]] == 1)    break;
                k++;
                A[s[j]]++;
            }
            p = max(p,k);
            k = 0;
        }
        return p;
    }
};