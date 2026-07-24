class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans = 0 , n = nums.size() , t , x;
        vector<bool> A(2048) , B(2048);
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                t = nums[i]^nums[j];
                if(A[t] == true)    continue;
                A[t] = true;
                for(int k = j ; k < n ; k++){
                    x = t^nums[k];
                    if(!B[x])   ans++;
                    B[x] = true;
                }
            }
        }
        return ans;
    }
};