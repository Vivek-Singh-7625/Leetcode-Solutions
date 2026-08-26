class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans = 0;
        string t;
        while(t.length() <= b.length()){  
            t += a;
            ans++;
        }
        t += a;
        int m = t.length() , n = b.length();
        for(int i = 0 ; i < m - n + 1 ; i++){
            if(t[i] != b[0])    continue;
            for(int j = 0 ; j < n ; j++){
                if(b[j] != t[i+j])  break;
                if(j == n-1)     return (i+j+a.length())/a.length(); 
            }
        }
        return -1;
    }
};