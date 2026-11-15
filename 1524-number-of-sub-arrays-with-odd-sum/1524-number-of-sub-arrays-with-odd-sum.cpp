class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size() , even = 1 , odd = 0 , mod = 1e9 + 7;
        for(int i = 0 ; i < n ; i++){
            if(i)   arr[i] += arr[i-1];
            if(arr[i]%2)    odd++;
            else    even++;
        }
        return (1ll*odd*even)%mod;
    }
};