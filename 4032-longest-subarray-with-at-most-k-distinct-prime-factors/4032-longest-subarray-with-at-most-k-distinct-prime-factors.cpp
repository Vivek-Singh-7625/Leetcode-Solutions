class Solution {
public:
    vector<bool> A ;
    vector<int> prime;
    Solution(){
        int n = 100001;
        A.assign(n,true);
        A[0] = false;
        A[1] = false;
        for(int i = 2 ; i < n ; i++){
            if(!A[i])   continue;
            prime.push_back(i);
            for(int j = 2*i ; j < n ; j += i){
                A[j] = false;
            }
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
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
                    if(prime[j] > t)  break;
                    if(t%prime[j] == 0){
                        while(t%prime[j] == 0)  t = t/prime[j];
                        factors[i].push_back(prime[j]);
                    }
                }
            }
        }
        vector<int> freq(mx+1,0);
        int uq = 0 , ans = 0 , l = 0 , st = 0;
        for(int i = 0 ; i < n ; i++){
            l++;
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
            ans = max(l-st,ans);
        }
        return ans;
    }
};