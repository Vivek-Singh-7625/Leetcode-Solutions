class Solution {
public:
    inline static vector<bool> A ;
    inline static vector<int> prime;
    static void Solver(){
        if (!prime.empty()) return;
        int n = 100001;
        A.assign(n,true);
        A[0] = false;
        A[1] = false;
        for(int i = 2 ; i*i < n ; i++){
            if(!A[i])   continue;
            for(int j = i*i ; j < n ; j += i){
                A[j] = false;
            }
        }
        for (int i = 2; i < n; i++) {
            if (A[i])   prime.push_back(i);
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        Solver();
        int mx = 0 , t = 0 , n = nums.size();
        vector<vector<int>> factors(nums.size()); 
        for(int i = 0 ; i < n ; i++){
            mx = max(mx,nums[i]);
            if(A[nums[i]]){
                factors[i].push_back(nums[i]);
            }
            else{
                t = nums[i];
                for(int j = 0 ; j < prime.size() ; j++){
                    if(prime[j]*prime[j] > t)  break;
                    if(t%prime[j] == 0){
                        while(t%prime[j] == 0)  t = t/prime[j];
                        factors[i].push_back(prime[j]);
                    }
                }
                if (t > 1)  factors[i].push_back(t);
            }
        }
        vector<int> freq(mx+1,0);
        int uq = 0 , ans = 0 , st = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < factors[i].size() ; j++){
                if(!freq[factors[i][j]])    uq++;
                freq[factors[i][j]]++;
            }
            while(uq > k){
                for(int x : factors[st]){
                    freq[x]--;
                    if(!freq[x])    uq--;
                }
                st++;
            }
            ans = max(i+1-st,ans);
        }
        return ans;
    }
};