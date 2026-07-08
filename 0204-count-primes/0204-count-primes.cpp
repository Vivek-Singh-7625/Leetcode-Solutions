class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> A(n,true);
        for(int i = 2 ; i*i < n ; i++){
            if(A[i] == true){
                for(int j = i*i ; j < n ; j += i){
                    A[j] = false;
                }
            }
        }
        int ans = 0;
        for(int i = 2 ; i < n; i++){
            if(A[i])   ans++;
        }
        return ans;
    }
    
};