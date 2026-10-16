class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size() , j , k , ans = 0;
        int sum , mod = 1e9 + 7  , l , r;
        for(int i = 0 ; i < n - 2 ; i++){
            j = i+1 , k = n-1;
            while(j < k){
                sum = arr[i] + arr[j] + arr[k];
                if(sum == target){
                    if(arr[j] == arr[k]){
                        l = k - j;
                        ans += l*(l+1)/2;
                        ans = ans%mod;
                        break;
                    }
                    l = 0 , r = 0;
                    while(j < k and arr[j] == arr[j+1]) j++ , l++;
                    while(j < k and arr[k] == arr[k-1]) k-- , r++;
                    j++,
                    k--;
                    ans += (l+1)*(r+1);
                    ans = ans%mod;
                }
                else if(sum > target)   k--;
                else    j++;
            }
        }
        return ans;
    }
};