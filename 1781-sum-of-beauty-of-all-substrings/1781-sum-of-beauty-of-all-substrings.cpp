class Solution {
public:
    int beautySum(string s) {
        int x = INT_MIN ,y = INT_MAX , idx , ans = 0;
        vector<int> a(26,0);
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = i ; j < s.length() ; j++){
                x = INT_MIN ,y = INT_MAX;
                idx = s[j]-'a';
                a[idx]++;
                for(int k = 0 ;  k < 26 ; k++){
                    if(a[k]){
                        y = min(y,a[k]);
                        x = max(x,a[k]);
                    }        
                }
                ans += (x-y);
            }
            fill(a.begin(),a.end(),0);
        }
        return ans;
    }
};