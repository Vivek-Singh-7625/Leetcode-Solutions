class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size() , even = 0 , ans = 0 , odd = 0 , mod = 1e9 + 7;
        for(int i = 1 ; i < n ; i++)    arr[i] += arr[i-1];
        for(int i = 0 ; i < n ; i++){
            if(arr[i]%2 == 0){
                even++;
                ans += odd;
            }
            else{
                ans += (1+even);
                odd++;
            }
            ans = ans%mod;
        }
        return ans;
    }
};