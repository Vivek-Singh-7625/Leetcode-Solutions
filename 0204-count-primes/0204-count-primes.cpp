class Solution {
public:
    inline static vector<int> ans;
    static void count(){
        if(!ans.empty())    return;
        ans = vector<int> (5e6+1,1);
        ans[0] = 0 , ans[1] = 0;
        int l = 5e6;
        for(int i = 2 ; i*i <= l ; i++){
            if(!ans[i]) continue;
            for(int j = i*i ; j <= l ; j += i){
                ans[j] = 0;
            }
        }
        for(int i = 1 ; i <= l ; i++)    ans[i] += ans[i-1];
    }
    int countPrimes(int n) {
        count();
        if(n == 0)  return 0;
        return ans[n-1];
    }
    
};