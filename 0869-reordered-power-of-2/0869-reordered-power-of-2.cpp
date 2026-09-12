class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> mpp;
        int s = 0;
        while(n){
            s++;
            mpp[n%10]++;
            n = n/10;
        }
        int t;
        string x;
        bool ans = true;
        for(int i = 0 ; i < 32 ; i++){
            t = (1 << i);
            x = to_string(t);
            if(x.length() != s) continue;
            ans = true;
            for(int j = 0 ; j < s ; j++){
                mpp[x[j]-'0']--;
                if(mpp[x[j]-'0'] < 0)   ans = false;
            }
            if(ans) return true;
            for(int j = 0 ; j < s ; j++){
                mpp[x[j]-'0']++;
            }
        }
        return false;
    }
};