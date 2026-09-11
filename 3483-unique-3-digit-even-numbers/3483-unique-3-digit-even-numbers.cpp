class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size() , ans = 0 ;
        vector<int> a(10);
        for(int i = 0 ; i < n ; i++)    a[digits[i]]++;
        for(int x = 1 ; x < 10 ; x++){
            if(a[x] == 0)   continue;
            a[x]--;
            for(int y = 0 ; y < 10 ; y++){
                if(a[y] == 0)   continue;
                a[y]--;
                for(int z = 0 ; z < 10 ; z += 2){
                    if(a[z])   ans++;
                }
                a[y]++;
            }
            a[x]++;
        }
        return ans;
    }
};