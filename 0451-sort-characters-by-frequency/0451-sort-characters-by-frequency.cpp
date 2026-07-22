class Solution {
public:
    string frequencySort(string s) {
        vector<int> A(62,0);
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z')  A[s[i]-'a']++;
            else if(s[i] >= 'A' && s[i] <= 'Z') A[s[i]-'A'+26]++;
            else if(s[i] >= '0' && s[i] <= '9') A[s[i]-'0'+52]++;
        }
        bool isz;
        int x, idx;
        string ans;
        char t;
        for(int i = 0 ; i < 62 ; i++){
            x = 0;
            idx = -1;
            isz = true;
            for(int j = 0 ; j < 62 ; j++){
                if(A[j] > x){
                    x = A[j];
                    idx = j;
                    isz = false;
                }
            }
            if(isz) break;
            if(idx < 26)    t = 'a' + idx;
            else if(idx < 52)   t = 'A' + idx - 26;
            else    t = '0' + idx - 52;
            for(int k = 0 ; k < x ; k++)    ans += t;
            A[idx] = 0;
        }
        return ans;
    }
};