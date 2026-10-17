class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        vector<int> freq(10,0);
        int idx , n = s.length();
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            idx = s[i] - '0';
            if(idx >= 0 and idx < 10)   freq[idx]++;
        }
        if(s[0] == '-'){
            for(int i = 9 ; i >= 0 ; i--){
                while(freq[i]){
                    freq[i]--;
                    ans = ans*10 + i;
                }
            }
            ans = ans*-1;
        }
        else{
            if(freq[0]){
                for(int i = 1 ; i < 10 ; i++){
                    if(freq[i]){
                        freq[i]--;
                        ans = ans*10 + i;
                        break;
                    }
                }
            }
            for(int i = 0 ; i < 10 ; i++){
                while(freq[i]){
                    freq[i]--;
                    ans = ans*10 + i;
                }
            }
        }
        return ans;
    }
};